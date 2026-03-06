#include <stdio.h>

int main() {
    int n, i, completed = 0, current_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    float avg_tat = 0, avg_wt = 0;

    // Input
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // Remaining time initially = burst time
    }

    while(completed < n) {
        int idx = -1;
        int min_rt = 9999;

        // Find process with smallest remaining time
        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && rt[i] > 0) {
                if(rt[i] < min_rt) {
                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            current_time++;   // CPU idle
        }
        else {
            rt[idx]--;        // Execute for 1 unit
            current_time++;

            if(rt[idx] == 0) {
                completed++;

                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                avg_tat += tat[idx];
                avg_wt += wt[idx];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}
