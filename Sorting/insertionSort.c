/*
    insertion Sort
1. stable sorting
2.best for if array is almost sorted 
3.space complexity O(1);
4.Time complexity 
   a. best cast O(n)
   b. worst cast O(n^2)   
   
*/


#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j>0;j--)
       if(arr[j]<arr[j-1]){
        swap(&arr[j],&arr[j-1]);
        }
        else{
            break;
        }
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n=(sizeof(arr))/(sizeof(arr[0]));
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

