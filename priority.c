#include <stdio.h>

void find_tat(int n, int bt[], int at[], int tat[], int ct[]) {
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }
}

void find_wt(int n, int bt[], int at[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
}

void priority_scheduling(int n, int bt[], int at[], int priority[]) {
    int process[n], wt[n], tat[n], ct[n];
    for (int i = 0; i < n; i++) process[i] = i + 1;

    // Sort by priority (lower number means higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = priority[j]; priority[j] = priority[j + 1]; priority[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                temp = process[j]; process[j] = process[j + 1]; process[j + 1] = temp;
            }
        }
    }

    find_tat(n, bt, at, tat, ct);
    find_wt(n, bt, at, wt, tat);
    int tot_wt=0,tot_tat=0;
    printf("\nPriority Scheduling:\n");
    printf("Process\tArrival\tBurst\tPriority\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], at[i], bt[i], priority[i], tat[i], wt[i]);
        tot_wt+=wt[i];
        tot_tat+=tat[i];
    }
    printf("\nAverage waiting time:%.2f",tot_wt/(float)n);
        printf("\nAverage Turn-around time:%.2f",tot_tat/(float)n);
    
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], priority[n];
    printf("Enter the burst time, arrival time, and priority of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d%d%d", &bt[i], &at[i], &priority[i]);
    }

    priority_scheduling(n, bt, at, priority);
    return 0;
}
