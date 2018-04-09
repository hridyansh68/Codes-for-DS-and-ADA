#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef struct Item             //Defining structure for each object
{
    float profit;
    float weight;
}Item;

bool cmp(Item a,Item b)         // sorts the objects on the basis of profit per unit weight
{
    float lambda1 = (a.profit/a.weight);
    float lambda2 = (b.profit/b.weight);
    return (lambda1 > lambda2);             //Returns True or False
}

int main(void)
{
    cout<<"Enter number of items: ";
    int N;
    cin>>N;                         //Number of items
    int i;
    Item object[N];
    int maxProfit = 0.0;
    for(i=0;i<N;i++)
    {
        cout<<"Enter weight of item "<<i+1<<": ";
        cin>>object[i].weight;
        cout<<"Enter profit of item "<<i+1<<": ";
        cin>>object[i].profit;
    }
    sort(object,object+N,cmp);      //sorts the objects on basis of profit per unit weight
    float capacity;                   //Maximum weight knapsack can hold
    cout<<"Enter the capacity of knapsack: ";
    cin>>capacity;
    for(i=0;i<N;i++)
    {
        if(object[i].weight <= capacity)        //If weight of item is less than capacity than take whole quantity of that item.
        {
            capacity = capacity - object[i].weight;    //Decrease the capacity by the weight of that object.
            maxProfit += object[i].profit;             //Since we take the hole quantity of that object so we add full profit of that object
            if(capacity == 0)                          //If capacity becomes 0 , it means that bag is full now.
                break;
        }
        else
        {
            maxProfit +=(capacity/object[i].weight)*(object[i].profit);   //If weight of object is more than capacity, add the fraction of that object.
            capacity = 0;    //Now bag is completely full ,therefore set capacity zero.
            if(capacity == 0)
                break;
        }
    }
    cout<<"Maximum profit that can be earned is: "<<maxProfit<<endl;   //Prints maximum profit
    return 0;
}
