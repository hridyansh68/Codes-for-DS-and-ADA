#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;
    return r1>r2;
}
int knapsack(vector <pair<int,int>> l,int w){
    int value=0;
    for(int i=0;i<l.size();i++){
        if((w-l[i].second)<0){
            value+=((double)l[i].first / l[i].second)*(w);
            break;
        }
        else{
            value+=l[i].first;
            w=w-l[i].second;
            
        }
      
    }
    return value;
}
int main() {
	vector <pair<int,int>> l;
    int n,a,b,w;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        l.push_back(make_pair(a,b));
    }
    cin>>w;
    sort(l.begin(),l.end(),cmp);
    cout<<knapsack(l,w);
    
 
     
	return 0;
}