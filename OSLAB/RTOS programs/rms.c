#include <stdio.h>

int main()
{
    int C[3] = {3,2,2};
    int T[3] = {20,5,10};
    float U;

    printf("Rate Monotonic Scheduling\n\n");

    printf("Tasks:\n");
    printf("T1 -> C=3 , T=20\n");
    printf("T2 -> C=2 , T=5\n");
    printf("T3 -> C=2 , T=10\n");

    /* Step 1 : CPU Utilization */
    U = (float)3/20 + (float)2/5 + (float)2/10;

    printf("\nCPU Utilization U = %.2f\n", U);
    printf("RMS Bound for 3 tasks = 0.78\n");

    if(U <= 0.78)
        printf("Tasks are Schedulable\n");
    else
    {
        printf("Tasks are NOT Schedulable\n");
        return 0;
    }

    /* Step 2 : Priority */
    printf("\nPriority (Smaller period -> Higher priority)\n");
    printf("T2 > T3 > T1\n");

    /* Step 3 : Execution timeline */
    printf("\nExecution Timeline (0 - 20)\n");

    printf("0 - 2 : T2\n");
    printf("2 - 4 : T3\n");
    printf("4 - 5 : T1\n");
    printf("5 - 7 : T2\n");
    printf("7 - 9 : T1\n");
    printf("9 -10 : Idle\n");
    printf("10-12 : T2\n");
    printf("12-14 : T3\n");
    printf("14-15 : Idle\n");
    printf("15-17 : T2\n");
    printf("17-20 : Idle\n");

    return 0;
}
