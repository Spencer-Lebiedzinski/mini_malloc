#include <stdio.h>
#include "my_malloc.h"

int main(void) {
    mm_init();
    printf("Allocator initialized.\n");
    return 0;
}