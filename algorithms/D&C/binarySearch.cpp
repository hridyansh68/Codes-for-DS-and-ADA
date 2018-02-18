#include <iostream>

using namespace std;

int binarySearch(int arr[],int l,int h,int k)
{
    while(l<=h)
    {
        int m=(l+h)/2;
        if(arr[m]==k){
            return m;
        }
        else if(arr[m]<k){
           return( binarySearch(arr,m+1,h,k));
        }
        else if(arr[m]>k){
            return(binarySearch(arr,l,m-1,k));
        }
    }
    if(l>h){
        return -1;
    }
}

int main()
{   int arr[10000],k,n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     cin>>k;
     cout<<binarySearch(arr,0,n-1,k);
     

    return 0;
}

