#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int arrL[n1],arrR[n2];
    
    for (int i=0;i<n1;i++)
    {
        arrL[i] = arr[l+i];
    }
    
    for (int i = 0;i<n2;i++){
        arrR[i] = arr[m+1+i];
    }
    
    int i = 0; 
    int j = 0; 
    int k = l; 
    while (i < n1 && j < n2)
    {
        if (arrL[i] <= arrR[j])
        {
            arr[k] = arrL[i];
            i++;
        }
        else
        {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
	int arr[] = {12,46,2,39,41,6,105,21};
	mergeSort(arr,0,7);
	for(int i =0;i<8;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}