#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void my_initialize_heap(int size);
int checkSize(int size);
void* my_malloc(int size);
void my_free(void *data);
//struct to represent an allocation block
struct Block {
    int block_size;  // # of bytes in the data section
    struct Block *next_block; // pointer to the next block
};
// The size of a Block value "overhead size"
const int sizeOfBlock = sizeof(struct Block);
// the size of a void*
const int voidPointer_Size = sizeof(void*);
// Global pointer always point to the first free block in the free list.
struct Block *free_head;

// initialize a buffer of the given size to use in my custom allocator
void my_initialize_heap(int size) {
    free_head = (struct Block*)malloc(size);
    free_head->block_size = size - sizeOfBlock - voidPointer_Size;
    free_head->next_block = NULL;
}

// memory block must be in multiples of sizeof(void*)
int checkSize(int size) {
    int remainder = size % voidPointer_Size;
    if(remainder == 0)
        return size;
    return size + voidPointer_Size - remainder;
}

void* my_malloc(int size) {
    // Size must be positive
    if(size <= 0) {
        printf("Size must be positive.\n");
        return NULL;
    }
    if(free_head == NULL){
        return NULL;
    }
    // previous block
    struct Block *prevBlock = NULL;
    // Current block
    struct Block* currBlock = free_head;
    // Next block
    struct Block* nextBlock = currBlock->next_block;
    // define new block
    struct Block* newBlock;
    bool flag = false;
    size = checkSize(size);
    // If the size is greater than the size of current block (looking for a block with a large enough size to
    // fit the reques)
    if(size > currBlock->block_size) {
        flag = true;
        while(size > currBlock->block_size && nextBlock != NULL) {
            prevBlock = currBlock;
            currBlock = nextBlock;
            nextBlock = currBlock->next_block;
        }
    }
    // Once you have found a block to fit the data size, decide whether you need to split that block.
    // A block that has enough memory is found (can split)
    if((currBlock->block_size - size) >= sizeOfBlock + voidPointer_Size){
        // find the byte location of where the new block will start, 
        // based on the size of the block you are splitting and the size of the allocation request.
        // Initialize a new block at that location 
        // by assigning its block_size and setting its next_block pointer to nextBlock.
        newBlock = (struct Block*)((char*)currBlock + (sizeOfBlock + size));
        
        newBlock->block_size = currBlock->block_size - (sizeOfBlock + size);
        newBlock->next_block = nextBlock;

        // Update current block size
        // Reduce the size of the original block appropriately
        currBlock->block_size = size;
        currBlock->next_block = newBlock;
        
        // Add new consition
        if(flag) { // there is prev free memory
            prevBlock->next_block = newBlock;
        }
        else { // no free memory in previous block
            free_head = newBlock;
        }
    }
    else { // If you cannot split the block, then you need to redirect pointers to the block to point to the block that follows it
        free_head = nextBlock;
    }
    // return the pointer to the data section
    return (void*) (currBlock + 1);
}
// Deallocates a value that was allocated on the data heap
void my_free(void *data) {
    if(!data)   // check for null pointer
    {
        printf("Null pointer.\n");
        return;
    }
    /* move backwards in memory to find the block's overhead information,
     and then link it into the free list.
    */
    struct Block *ptr = ((struct Block *)data - 1);
    ptr->next_block = free_head;
    free_head = ptr;
}
