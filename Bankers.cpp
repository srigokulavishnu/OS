#include <stdio.h>

int n, m; // n = number of processes, m = number of resources
int alloc[10][10], max[10][10], avail[10], need[10][10];
int safeSeq[10];

void calculateNeed() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe() {
    int work[10], finish[10] = {0}, count = 0;
    
    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}

int main() {
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    calculateNeed();

    if (isSafe()) {
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is in an unsafe state. Deadlock may occur!\n");
    }

    return 0;
}
