#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_FILES 10

struct Block {
    int next;
};

struct File {
    int start;
    int blocks;
};

void linkedAllocation() {
    struct Block disk[MAX_BLOCKS] = {0}; // Initialize disk blocks
    struct File files[MAX_FILES];       // Store file info
    int numFiles, i, j, start, blocks, next;

    printf("Enter number of files: ");
    scanf("%d", &numFiles);

    for (i = 0; i < numFiles; i++) {
        printf("\nEnter starting block and number of blocks for file %d: ", i + 1);
        scanf("%d %d", &start, &blocks);

        files[i].start = start;
        files[i].blocks = blocks;

        next = start;
        for (j = 0; j < blocks; j++) {
            if (disk[next].next != 0) {
                printf("Block %d is already allocated! Try again.\n", next);
                return;
            }
            printf("Allocating block %d\n", next);
            if (j < blocks - 1) {
                printf("Enter next block: ");
                scanf("%d", &disk[next].next);
                next = disk[next].next;
            } else {
                disk[next].next = -1; // Mark last block
            }
        }
    }

    // Display allocated blocks
    printf("\nFile Allocation Table:\n");
    for (i = 0; i < numFiles; i++) {
        printf("File %d: Start Block = %d, Blocks = %d\n", i + 1, files[i].start, files[i].blocks);
    }
}

int main() {
    linkedAllocation();
    return 0;
}
