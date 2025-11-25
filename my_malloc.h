// mymalloc.h
#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>  // for size_t

// Initialize the allocator (usually called automatically)
void mm_init(void);

// Allocate memory (like malloc)
void *my_malloc(size_t size);

// Free memory (like free)
void my_free(void *ptr);

// Allocate zero-initialized memory (like calloc)
void *my_calloc(size_t nmemb, size_t size);

// Resize a previously allocated block (like realloc)
void *my_realloc(void *ptr, size_t new_size);

// Optional: debug function to print the state of the heap
void mm_dump(void);

#endif // MYMALLOC_H

