#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*
In a real-time system, there is a need to make the allocation/free of blocks of memory of
certain size happens in a deteministic time. Design and implement such a memory
allocator. The memory allocator will manage a pool of blocks of fixed size. When
allocation is requested, the allocator would return a block at a time. The user
can free the allocated block by returning it back to the allocator.

The allocator manages a certain number of blocks and doesn’t grow beyond this
number. The system can have multiple allocators each of its own fixed block size
and its own max block count. 
*/

/*Ex: Ask for 5 bytes with 3 byte alignment
00 01 02 03 04 05 06 07 08
Malloc returns 04
The function needs to return 06
Free at 04
*/

void* aligned_malloc(size_t required_bytes, size_t alignment)
{
    void *original_addr;
    size_t actual_size = required_bytes + sizeof(void*) + alignment;
    if((original_addr = (void * ) malloc(actual_size)) == NULL)
    {
        return NULL;
    }

    void* aligned_addr = original_addr + sizeof(void*);
    size_t offset = alignment - ((size_t)aligned_addr %alignment);
    aligned_addr += offset;

    *((void**)aligned_addr - 1) = original_addr;
    
    // print the addrs
    printf("original_addr   %p\n", original_addr);
    printf("aligned_addr    %p\n", aligned_addr);
    printf("aligned_addr-1  %p\n", aligned_addr-1);
    return aligned_addr;
}

void aligned_free(void *aligned_addr) {
    /* Find the original address which was stored at aligned_addr - 1 */
    void* original_addr = *((void**)aligned_addr - 1);
    printf("free addr %p\n", original_addr);
    free(original_addr);
}

int main(int argc, char* argv[]) {
    for(size_t i = 1; i < 35; i++){
        size_t alignment = i;
        size_t need_bytes = i*2;
        void* ptr = aligned_malloc(need_bytes, alignment);
        aligned_free(ptr);
        printf("Got %lu bytes aligned %lu at ptr %p\n", need_bytes, alignment, ptr);
    }

    return 0;
}
