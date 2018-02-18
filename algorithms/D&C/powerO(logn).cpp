#include <iostream>
using namespace std;
long int power(long int x,long int y){
    if(y==0){
        return 1;
    }
    long int temp = power(x,y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}
int main() {
	cout<<power(3,200);
	return 0;
}