/*THIS PROBLEM USES THE CONCEPT OF DYNAMIC PROGRAMMING*/
/*PRINCIPLE OF OPTIMALITY IS ALSO USED*/
#include<bits/stdc++.h>
using namespace std;
typedef struct object
{
    int weight;
    int profit;
}object;

int max_val(int a,int b)
{
    return (a > b)? a : b;
}

int knapsack(int capacity,object *item,int N)
{
    if(N==0||capacity==0)
        return 0;
    if(item[N-1].weight > capacity)
    {
        return knapsack(capacity,item,N-1);
    }
    else
    {
        return max_val((item[N-1].profit + knapsack((capacity - item[N-1].weight) ,item,N-1)) , knapsack(capacity,item,N-1));
    }
}

int main(void)
{
    int N,i,capacity;
    cout<<"ENTER NO. OF OBJECTS: ";
    cin>>N;
    object item[N];
    for(i=0;i<N;i++)
    {
        cout<<"ENTER WEIGHT AND PROFIT: ";
        cin>>item[i].weight>>item[i].profit;
    }
    cout<<"ENTER CAPACITY OF KNAPSACK: ";
    cin>>capacity;
    int max_profit = knapsack(capacity,item,N);
    cout<<"MAX PROFIT IS: "<<max_profit;
    return 0;
}
