#include <stdio.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

struct File {
    int indexBlock;
    int numBlocks;
    int blocks[MAX_BLOCKS];
};

void indexedAllocation() {
    struct File files[MAX_FILES];
    int numFiles, i, j;

    printf("Enter number of files: ");
    scanf("%d", &numFiles);

    for (i = 0; i < numFiles; i++) {
        printf("\nEnter index block for file %d: ", i + 1);
        scanf("%d", &files[i].indexBlock);

        printf("Enter number of file blocks: ");
        scanf("%d", &files[i].numBlocks);

        printf("Enter the block numbers: ");
        for (j = 0; j < files[i].numBlocks; j++)
            scanf("%d", &files[i].blocks[j]);
    }

    // Display file allocation table
    printf("\nFile Allocation Table:\n");
    for (i = 0; i < numFiles; i++) {
        printf("File %d: Index Block = %d\n", i + 1, files[i].indexBlock);
        for (j = 0; j < files[i].numBlocks; j++)
            printf("  Block %d stored at %d\n", j + 1, files[i].blocks[j]);
    }
}

int main() {
    indexedAllocation();
    return 0;
}
