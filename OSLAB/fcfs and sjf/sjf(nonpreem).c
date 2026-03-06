int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int bt[n], wt[n], tat[n];

    for(int i=0;i<n;i++){
        printf("Burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    // Sorting processes by burst time
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(bt[i] > bt[j]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");

    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    return 0;
}
