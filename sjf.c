#include <stdio.h>
#include <stdlib.h>

void find_tat(int p[], int b[], int a[], int n, int tat[]) {
    int c[n];
    c[0] = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = c[i] - a[i];
    }
}

void find_wt(int p[], int b[], int a[], int n, int wt[]) {
    int tat[n];
    find_tat(p, b, a, n, tat);
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - b[i];
    }
}

void find_avgtime(int p[], int b[], int a[], int n) {
    int tot_tat = 0, tot_wt = 0;
    int wt[n], tat[n];
    find_tat(p, b, a, n, tat);
    find_wt(p, b, a, n, wt);

    printf("\nProcess\tArrival\tBurst\ttat\twt\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], a[i], b[i], tat[i], wt[i]);
        tot_tat += tat[i];
        tot_wt += wt[i];
    }

    printf("Average waiting time: %f\n", tot_wt / (float)n);
    printf("Average Turnaround time: %f\n", tot_tat / (float)n);
}

void sort_processes(int p[], int b[], int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1] || (a[j] == a[j + 1] && b[j] > b[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void non_preemptive_sjf(int p[], int b[], int a[], int n) {
    int remaining[n];
    int completed = 0, current_time = 0;
    int wt[n], tat[n];
    int is_completed[n]; 
    for (int i = 0; i < n; i++) {
        remaining[i] = b[i];
        is_completed[i] = 0; 
    }

    while (completed < n) {
        int min_burst = -1;
        int min_index = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] <= current_time && !is_completed[i]) {
                if (min_burst == -1 || remaining[i] < min_burst) {
                    min_burst = remaining[i];
                    min_index = i;
                }
            }
        }

        if (min_index == -1) {

            current_time++;
            continue;
        }

        current_time += remaining[min_index];
        remaining[min_index] = 0; 
        is_completed[min_index] = 1; 
 	completed++;

       tat[min_index] = current_time - a[min_index];
        wt[min_index] = tat[min_index] - b[min_index];
    }


    find_avgtime(p, b, a, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    int burst[n], arrival[n];
    printf("Enter the burst time and arrival time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time of p%d: ", i + 1);
        scanf("%d%d", &burst[i], &arrival[i]);
    }

    sort_processes(process, burst, arrival, n);

    printf("\nSorted Processes (Based on Arrival Time and Burst Time):\n");
    printf("Process    Arrival    Burst\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i]);
    }

    non_preemptive_sjf(process, burst, arrival, n);

    return 0;
}

