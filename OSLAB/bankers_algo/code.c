#include <stdio.h>

int main() {
    int n, m;

    // n = number of processes
    // m = number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Maximum Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int finish[n], safeSeq[n];
    for(int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(int p = 0; p < n; p++) {

            // Check if process is unfinished
            if(finish[p] == 0) {

                int possible = 1;

                // Check if all resources can be allocated
                for(int j = 0; j < m; j++) {
                    if(need[p][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }

                // If resources can be allocated
                if(possible) {

                    // Release resources after execution
                    for(int j = 0; j < m; j++) {
                        avail[j] += alloc[p][j];
                    }

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        // No process could be allocated
        if(found == 0) {
            printf("\nSystem is NOT in safe state.\n");
            return 0;
        }
    }

    // Safe sequence exists
    printf("\nSystem is in SAFE state.\nSafe Sequence: ");

    for(int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);

        if(i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
