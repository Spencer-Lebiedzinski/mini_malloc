// mymalloc.c
#include "my_malloc.h"
#include <stddef.h>

#define HEAP_SIZE 1024 * 1024 //1MB heap size

typedef struct block_header {
    size_t size;      // size of the *payload* in bytes (not counting header)
    int free;         // 1 if free, 0 if allocated
    struct block_header *next; // pointer to the next block
} block_header_t;

// The raw heap memory our allocator manages
static unsigned char heap[HEAP_SIZE];

// Pointer to the first block in the heap (head of our block list)
static block_header_t *free_list = NULL;

// Flag so we know if we've already set up the heap
static int heap_initialized = 0;

void mm_init(void) {
    // Point the free_list to the very beginning of the heap array
    free_list = (block_header_t *)heap;

    // The total size we can give to the user is the heap size minus the header itself
    free_list->size = HEAP_SIZE - sizeof(block_header_t);

    // Mark this block as free (nobody has allocated from it yet)
    free_list->free = 1;

    // There is only one block right now, so next is NULL
    free_list->next = NULL;

    // Remember that we've initialized the heap
    heap_initialized = 1;
}