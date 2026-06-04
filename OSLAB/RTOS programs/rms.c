#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int burst[n], period[n];
    int remaining[n], next_release[n];

    for(int i = 0; i < n; i++)
    {
        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &burst[i]);

        printf("Task %d Period: ", i + 1);
        scanf("%d", &period[i]);

        remaining[i] = 0;
        next_release[i] = 0;
    }

    int sim_time;

    printf("\nEnter simulation time: ");
    scanf("%d", &sim_time);

    int gantt[sim_time];

    printf("\nTime\tRunning Task\n");

    for(int t = 0; t < sim_time; t++)
    {
        /* Release tasks at their periods */
        for(int i = 0; i < n; i++)
        {
            if(t == next_release[i])
            {
                remaining[i] = burst[i];
                next_release[i] += period[i];
            }
        }

        int chosen = -1;
        int min_period = 9999;

        /* Select highest priority task
           (smallest period = highest priority) */
        for(int i = 0; i < n; i++)
        {
            if(remaining[i] > 0 && period[i] < min_period)
            {
                min_period = period[i];
                chosen = i;
            }
        }

        if(chosen == -1)
        {
            printf("%d\tIDLE\n", t);
            gantt[t] = -1;
        }
        else
        {
            printf("%d\tT%d\n", t, chosen + 1);
            gantt[t] = chosen + 1;
            remaining[chosen]--;
        }
    }

    /* Gantt Chart */
    printf("\nExecution Order (Rate Monotonic):\n");
    for(int t = 0; t < sim_time; t++)
    {
        if(gantt[t] == -1)
            printf("IDLE ");
        else
            printf("T%d ", gantt[t]);
    }

    printf("\n\nGantt Chart:\n|");

    for(int t = 0; t < sim_time; t++)
    {
        if(gantt[t] == -1)
            printf("IDLE|");
        else
            printf("T%d|", gantt[t]);
    }

    printf("\n0");

    for(int t = 1; t <= sim_time; t++)
    {
        printf(" %d", t);
    }

    printf("\n");

    return 0;
}
