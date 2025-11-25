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