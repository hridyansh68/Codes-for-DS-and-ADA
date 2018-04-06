#include<bits/stdc++.h>
using namespace std;
typedef struct object
{
    int deadline;
    int profit;
}object;
bool cmp(object a,object b)
{
    return (a.profit < b.profit);
}
int main(void)
{
    int N,i,c;
    cout<<"Enter number of jobs : ";
    cin>>N;
    object job[N];
    for(i=0;i<N;i++)
    {
        cout<<"Enter deadline and profit: ";
        cin>>job[i].deadline>>job[i].profit;
    }
    cout<<"Enter number of days you have to work : ";
    cin>>c;
    int output[c] = {0};
    sort(job,job+N,cmp);
    int cnt = 0;
    i = N-1;
    while(cnt != c)
    {
        if(output[job[i].deadline - 1] ==0)
        {
            output[job[i].deadline - 1] = job[i].profit ;
            cnt++;
        }
        else if()
    }
    return 0;
}

