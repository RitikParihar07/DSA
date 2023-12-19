/*
     Selection Sort
1.Not stable sorting
2.Perform in small arrays/list
3.space complexity O(1);
3.Time complexity 
   a. best cast O(n^2)
   b. worst cast O(n^2)
   
*/


#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++)
       if(arr[j]<arr[i]){
        swap(&arr[j],&arr[i]);
        }
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n=(sizeof(arr))/(sizeof(arr[0]));
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

