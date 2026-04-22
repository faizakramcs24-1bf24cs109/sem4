#include <stdio.h>

void sort(int profit[], int weight[], float ratio[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(ratio[j] < ratio[j + 1]) {
                // swap ratio
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                // swap profit
                int t = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = t;

                // swap weight
                t = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = t;
            }
        }
    }
}

void fractionalKnapsack(int profit[], int weight[], int n, int capacity) {
    float ratio[n], fraction[n];
    float totalProfit = 0.0;

    // calculate ratio
    for(int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / weight[i];
        fraction[i] = 0.0;
    }

    sort(profit, weight, ratio, n);

    for(int i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            fraction[i] = 1.0;
            totalProfit += profit[i];
            capacity -= weight[i];
        } else {
            fraction[i] = (float)capacity / weight[i];
            totalProfit += profit[i] * fraction[i];
            break;
        }
    }

    // print selected items
    printf("Selected Items (Profit, Weight, Fraction):\n");
    for(int i = 0; i < n; i++) {
        if(fraction[i] > 0) {
            printf("(%d, %d) -> %.2f\n", profit[i], weight[i], fraction[i]);
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int n = 3;
    int capacity = 50;

    fractionalKnapsack(profit, weight, n, capacity);

    return 0;
}
