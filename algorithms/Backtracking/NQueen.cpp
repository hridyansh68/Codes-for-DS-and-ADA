#include <iostream>
using namespace std;
#define N 5
int t=0;
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
bool utilFunc(int col,int n,int solmat[N][N]){
    if(col==n-1){
        
        for(int i=0;i<n;i++){
            if(isSafe(solmat,i,col)){
                solmat[i][col]=1;
                 return true;
            }
        }
        return false;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(solmat,i,col)){
            solmat[i][col]=1;
            if(utilFunc(col+1,n,solmat)==false){
                solmat[i][col]=0;
            }
            else{
               return true;
            }
        }
    }
    return false;
    
}
bool Queen(){
    int solmat[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        solmat[i][j]=0;
        }
    }
    if(utilFunc(0,N,solmat)==false){
        cout<<"not possible";
        return false;
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
            cout<<solmat[i][j]<<" ";
        }
        cout<<endl;
    }
    return true;
}

int main() {
	Queen();
	return 0;
}