/*
   quick sort
1. best technique
2. best case time complexity O(nlogn)
3. Space complexity O(1)
4. Stable sort

   
*/
#include <stdio.h>
int partition(int arr[], int low,int high){
    
    //pivot koi bhi element ho skta hai hum last wla le re button
    
    int pivot=arr[high];
    
    // two pointer use karnge tum i and j 
    //i starting mai -1 rahega then agr arr[j] chota hoa pivot se toh tabhi i ++ hoga 
    // but j har bar ++ hoga 
    
    int i=low-1;
    
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            //swap kiya hai idhar function bana ke bhi kar skti ho
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    // return kar denge pivot ka index 
    // i se ekk baad wala hi hoga 
    return i+1;
}


void quicksort(int arr[], int l, int r) {
    // l-> left side , r-> right side
    // ager left chota hai  tabhi code run karega 
    if (l < r) {
        
        //hum logo ko pivot ko uski shi position mai rakhna hai 
        // pivot koi bhi ekk element ho skta hai array mai se uske aage usse chote element honge uske baad usse baade 
        
        int pivotIndex = partition(arr, l, r);// then check partition function 

        //reccursion use karke baki place mai bhi hum sort kr lenge 
        // pivotIndex-1 iss lea kyu ki pivotIndex wala element to apni shi position mai aa gya 
        
        quicksort(arr, l, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, r);
    }
    
}


int main()
{
    
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    
    
    // quick sort call hoga 
    // starting and last index arugument mai dalnge 
    quicksort(arr, 0, n - 1);


    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

