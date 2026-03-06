#include <stdio.h>

int main() {
    int n, i, time = 0, smallest;
    int bt[10], at[10], rt[10];
    int wt[10], tat[10], complete = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }

    while(complete != n) {
        smallest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(smallest == -1 || rt[i] < rt[smallest])
                    smallest = i;
            }
        }

        if(smallest == -1) {
            time++;
            continue;
        }else{

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0) {
            complete++;  //comp inc
            int finish = time;

            wt[smallest] = finish - bt[smallest] - at[smallest];
            tat[smallest] = bt[smallest] + wt[smallest];

            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }}

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("Average Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}