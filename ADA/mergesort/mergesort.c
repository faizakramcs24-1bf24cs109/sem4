
#include <stdio.h>
void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

  
    int L[n1], R[n2];

    
    for (i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    
    i = 0; 
    j = 0; 
    k = low; 
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        
        int mid = low + (high - low) / 2;

       
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}


int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    return 0;
}
