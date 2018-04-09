#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
class Graph{
    int v;
    list<pair<int,int>> *adj;
    public:
    Graph(int v);
    void addedge(int u,int v,int w);
    void prims();
};
Graph::Graph(int v){
    this->v=v;
    adj = new list<ipair>[v];
}
void Graph::addedge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void Graph::prims(){
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    int s=0;
    vector<int> key(v, INF);
    vector<int> parent(v,INF);
    vector<bool> inmst(v,false);
    pq.push(make_pair(0,s));
    key[s]  = 0;
    while(!pq.empty()){
      int u =  pq.top().second;
      pq.pop();
      inmst[u]=true;
      list<pair<int,int>>::iterator it;
      for(it=adj[u].begin();it!=adj[u].end();it++){
          int v= (*it).first;
          int w = (*it).second;
          if(inmst[v]==false&&w<key[v]){
              key[v]=w;
              parent[v]=u;
              pq.push(make_pair(w,v));
          }
      }
    }
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"-"<<i<<endl;
        
    }
}
int main() {
   int v,e,a,b,w;
   cin>>v;
   Graph g(v);
   cin>>e; 
   for(int i=0;i<e;i++){
       cin>>a>>b>>w;
       g.addedge(a,b,w);
   }
   g.prims();
	return 0;
}