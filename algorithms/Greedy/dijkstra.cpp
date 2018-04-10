#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> ipair;
class Graph
{
    int V;    
    list< pair<int, int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::shortestPath(int s){
    set <pair<int,int>> setds;
    vector<int> d(V,INF);
   
    d[s]=0;
    setds.insert(make_pair(0,s));
    
    while(!setds.empty()){
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
       int  u = tmp.second;
        list<pair<int,int>>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            int v=(*it).first;
           int w=(*it).second;
            if(d[v]>d[u]+w){
               if (d[v] != INF)
                    setds.erase(setds.find(make_pair(d[v], v)));
                
                
                d[v] = d[u] + w;
                setds.insert(make_pair(d[v], v)); 
            }
        }
    }
    
     for(int i=0;i<V;i++){
        cout<<i<<" "<<d[i]<<endl;}
}
int main() {
     int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
     g.shortestPath(0);
 
	return 0;
}