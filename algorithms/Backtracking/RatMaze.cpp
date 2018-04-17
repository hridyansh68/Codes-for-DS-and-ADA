#include <iostream>
using namespace std;
#define N 4
bool isSafe(int maze[N][N],int nx,int ny){
    return(maze[nx][ny]!=0&&nx>=0&&nx<N&&ny>=0&&ny<N);
}
bool utilFunc(int maze[N][N],int solMat[N][N],int nx[],int ny[],int sx,int sy,int fx,int fy){
    if(sx==fx&&sy==fy){
        solMat[sx][sy]=1;
        return true;
    }
    for(int i=0;i<2;i++){
        int npx=sx+nx[i];
        int npy=sy+ny[i];
        if(isSafe(maze,npx,npy)){
            solMat[npx][npy]=1;
            // cout<<npx<<" "<<npy<<endl;
            if(utilFunc(maze,solMat,nx,ny,npx,npy,fx,fy)==false)
             {  solMat[npx][npy]=0;}
             else{
                 return true;
             }
        }
    }
    return false;
}
bool pathForRat(int maze[N][N],int sx,int sy,int fx,int fy){
    int solMat[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            solMat[i][j]=0;
        }
    }
    solMat[sx][sy]=1;
    int nx[2]={0,1};
    int ny[2]={1,0};
    if(utilFunc(maze,solMat,nx,ny,sx,sy,fx,fy)==false){
        cout<<"not possible";
        return false;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
           cout<<solMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
	int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    pathForRat(maze,3,0,3,3);
    
	return 0;
}