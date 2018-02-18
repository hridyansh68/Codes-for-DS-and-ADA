#include <iostream>
using namespace std;

//fibonacci series 0,1,1,2,3,5......

long int lookup[100];

long int fibon(long int n){
    if(lookup[n]==-1){
        if(n<=1){
            lookup[n] = n;
        }
        else {
            lookup[n] = fibon(n-1) + fibon(n-2);
        }
    }
    
    return lookup[n];
}

int main() {
    for(int i =0;i<100;i++){
        lookup[i]= -1;
    }
    long int n = 5;
    cout<<fibon(n-1);
	return 0;
}