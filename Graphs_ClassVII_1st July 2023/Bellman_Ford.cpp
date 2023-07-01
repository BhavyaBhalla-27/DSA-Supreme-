#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;
    void addEdge(int u,int v,int wt,bool direction){
        // direction = 1 -> undirected
        // direction = 0 -> directed
        adjList[u].push_back({v,wt});
        if(direction == 1){
            adjList[v].push_back({u,wt});
        }
    }
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    bool bellmanford(int n,int src){
        // Assuming directed graph
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        // n - 1 relaxation 
        for(int i = 0;i<n-1;i++){
            // for all edges
            for(auto t : adjList){
                for(auto nbr : t.second){
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        // cout<<"Printing distance array"<<endl;
        // for(auto i : dist)
        //     cout<<i<<" ";
    
        // Bellman ford is completed but now checking for negative cycle also
        // Running for one more time and if updation then simply return negative cycle
        bool negativeCycle = false;
        for(auto t : adjList){
            for(auto nbr : t.second){
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    negativeCycle = true;
                    break;
                }
            }
        }
        return negativeCycle;
    }
    
};

int main(){
    Graph g;
    g.addEdge(0,1,-1,0);
    g.addEdge(0,2,4,0);
    g.addEdge(1,2,3,0);
    g.addEdge(1,3,2,0);
    g.addEdge(1,4,2,0);
    g.addEdge(3,1,1,0);
    g.addEdge(3,2,5,0);
    g.addEdge(4,3,-3,0);
    
    bool ans = g.bellmanford(5,0);
    if(ans)
        cout<<"Negative cycle found";
    else    
        cout<<"Negative cycle not found";
    
    return 0;
}