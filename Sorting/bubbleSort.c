/*
     Bubble Sort
1.stable sort  (color sort)
2.Also know as exchange sort / Sinking sort
3.space complexity O(1);
3.Time complexity 
   a. best cast O(n)
   b. worst cast O(n^2)
   
*/


#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                // int temp=arr[j];
                // arr[j]=arr[j-1];
                // arr[j-1]=temp;
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}
int main()
{
    int arr[]={5,4,3,2,1};
    int n=(sizeof(arr))/(sizeof(arr[0]));
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

