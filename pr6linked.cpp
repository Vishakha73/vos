#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

struct Block {
    int block_number;
    struct Block* next;
};

typedef struct Block Block;

Block* createBlock(int block_number) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    if (new_block == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_block->block_number = block_number;
    new_block->next = NULL;
    return new_block;
}

void printFile(Block* head) {
    printf("File blocks: ");
    while (head != NULL) {
        printf("%d ", head->block_number);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Block* file_head = NULL;
    Block* current_block = NULL;
    int num_blocks;

    printf("Enter the number of blocks in the file: ");
    scanf("%d", &num_blocks);

    if (num_blocks > MAX_BLOCKS || num_blocks <= 0) {
        printf("Invalid number of blocks\n");
        return 1;
    }

    printf("Enter block numbers: ");
    for (int i = 0; i < num_blocks; i++) {
        int block_number;
        scanf("%d", &block_number);
        if (block_number < 0) {
            printf("Invalid block number\n");
            return 1;
        }

        if (file_head == NULL) {
            file_head = createBlock(block_number);
            current_block = file_head;
        } else {
            current_block->next = createBlock(block_number);
            current_block = current_block->next;
        }
    }

    printFile(file_head);

    // Free memory
    while (file_head != NULL) {
        current_block = file_head;
        file_head = file_head->next;
        free(current_block);
    }

    return 0;
}
