#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){

    return p1.second>p2.second;
}

int jobseqp(vector <pair<int,int>> l){
    int profit = 0;
    int carr[100];
    for(int i=0;i<100;i++){
        carr[i]=-1;
    }
    
    for(int i=0;i<l.size();i++){
        int t=l[i].first;
        int p=l[i].second;
        for(int j=t-1;j>=0;j--){
         if(carr[j]==-1){
             carr[j]=p;
             profit+=p;
             break;
         }
        }
    }
        
        return profit;
}
int main() {
    vector <pair<int,int>> l;
    int n,d,p;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d>>p;
        l.push_back(make_pair(d,p));
    }
    sort(l.begin(),l.end(),cmp);
    cout<<jobseqp(l);
    
	return 0;
}