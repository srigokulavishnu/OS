#include <stdio.h>

void round_robin(int n, int bt[], int at[], int quantum) {
    int rem_bt[n], wt[n], tat[n], t = 0;
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    tat[i] = t - at[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
    for (int i = 0; i < n; i++) wt[i] = tat[i] - bt[i];

    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Process\tArrival\tBurst\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);
    }
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n];
    printf("Enter the burst time and arrival time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d%d", &bt[i], &at[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    round_robin(n, bt, at, quantum);
    return 0;
}
