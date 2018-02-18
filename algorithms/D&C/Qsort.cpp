#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int count = 0;
    for(int i=0;i<=high-1;i++){
        if(arr[i]<pivot){
            int temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
    int temp = arr[count];
    arr[high] = temp;
    arr[count] = pivot;
    
    return count;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int p = partition(arr,low,high);
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main() {
     int arr[] = {21,3,7,1,27,53,37};
     quickSort(arr,0,6);
     for(int i =0;i<7;i++)
     {
         cout<<arr[i]<<" ";
     }
	return 0;
}