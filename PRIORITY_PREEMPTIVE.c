#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20], rt[20], rt_final[20];
    int ct[20], tat[20], wt[20];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: "); scanf("%d",&at[i]);
        printf("Burst Time: "); scanf("%d",&bt[i]);
        printf("Priority (Lower number = Higher priority): "); scanf("%d",&pr[i]);

        rt[i] = bt[i];        // remaining time
        rt_final[i] = bt[i];  // store original remaining time
    }

    // Preemptive Priority Scheduling
    while(completed < n)
    {
        int hp = 9999, p = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(pr[i] < hp)
                {
                    hp = pr[i];
                    p = i;
                }
            }
        }

        if(p == -1)
        {
            time++;
        }
        else
        {
            rt[p]--;            // decrease remaining time
            rt_final[p]--;      // keep track for RT column
            time++;

            if(rt[p] == 0)
            {
                ct[p] = time;
                tat[p] = ct[p] - at[p];
                wt[p] = tat[p] - bt[p];
                completed++;
            }
        }
    }

    // Output table
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i], rt_final[i]);

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f\n", avg_wt/n);

    return 0;
}
