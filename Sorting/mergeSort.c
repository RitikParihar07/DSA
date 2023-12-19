/*
   Merge Sort
1. This is the best sorting technique it always takes O(nlog) time 
2. but drawback is that it take O(n) space 
3. not stable 

*/
#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    int arr2[high + 1];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            arr2[k] = arr[i];
            i++;
        } else {
            arr2[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        arr2[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        arr2[k] = arr[j];  // Corrected from arr[i] to arr[j]
        j++;
        k++;
    }

    // Copy elements back to the original array
    for (int x = low; x <= high; x++) {
        arr[x] = arr2[x];
    }
}


void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        
        int mid = low + (high - low) / 2;

   
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);
    
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}

