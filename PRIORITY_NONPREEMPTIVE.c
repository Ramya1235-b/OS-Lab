#include <stdio.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[20], bt[20], pr[20], rt[20];
    int ct[20], tat[20], wt[20];
    int completed[20] = {0};

    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];   // initial remaining time
    }

    // Scheduling
    while(done < n)
    {
        int hp = 9999, p = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
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
            time += rt[p];
            ct[p] = time;

            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            rt[p] = 0;   // process finished
            completed[p] = 1;
            done++;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i], rt[i]);

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT = %.2f", avg_wt/n);

    return 0;
}
