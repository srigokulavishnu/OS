#include <stdio.h>

#define MAX_FILES 10

struct File {
    int start, size;
};

void contiguousAllocation() {
    struct File files[MAX_FILES];
    int disk[100] = {0}; // Simulated disk
    int n, i, j, start, size;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start block and size for file %d: ", i + 1);
        scanf("%d %d", &start, &size);

        int freeSpace = 1;
        for (j = start; j < start + size; j++) {
            if (disk[j] == 1) {
                freeSpace = 0;
                break;
            }
        }

        if (freeSpace) {
            files[i].start = start;
            files[i].size = size;
            for (j = start; j < start + size; j++)
                disk[j] = 1; // Mark blocks as occupied
            printf("File %d allocated from %d to %d\n", i + 1, start, start + size - 1);
        } else {
            printf("Not enough contiguous space for file %d\n", i + 1);
        }
    }
}

int main() {
    contiguousAllocation();
    return 0;
}
