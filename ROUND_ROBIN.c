#include <stdio.h>

int main() {
    int n, i, time = 0, done = 0, tq;
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: "); scanf("%d",&at[i]);
        printf("Burst Time: "); scanf("%d",&bt[i]);
        rt[i] = bt[i]; // Remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(done < n) {
        int flag = 0;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    done++;
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
                flag = 1;
            }
        }
        if(flag == 0) time++; // if no process is ready
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
        avg_tat += tat[i]; avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f\n", avg_wt/n);

    return 0;
}
