#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
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
    void topoSort(int src,unordered_map<int,bool>&visited,stack<int>&ans){
            visited[src] = true;
            for(auto neighbour : adjList[src]){
                if(!visited[neighbour.first]){
                    topoSort(neighbour.first,visited,ans);
                }
            }
            // while returing store node in stack
            ans.push(src);
    }
    void shortestPath(int dest,stack<int>&topoOrder,int n){
        vector<int>dist(n,INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        for(auto nbr : adjList[0]){
            if(dist[0] + nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }
        while(!topoOrder.empty()){
            int topElement = topoOrder.top();
            topoOrder.pop();
            if(dist[topElement]!=INT_MAX){
                for(auto nbr : adjList[topElement]){
                    if(dist[topElement] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }
        for(auto i : dist){
            cout<<i<<" ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,5,0);
    g.addEdge(0,2,3,0);
    g.addEdge(2,1,2,0); 
    g.addEdge(1,3,3,0);
    g.addEdge(2,4,6,0);
    g.addEdge(4,3,1,0);
    g.addEdge(2,3,5,0);
    int n = 5;
    g.printAdjList();
    stack<int>topoOrder;
    unordered_map<int,bool>visited;
    g.topoSort(0,visited,topoOrder);
    cout<<"Printing shortest path"<<endl;
    int dest = 3;
    g.shortestPath(dest,topoOrder,n);
    return 0;
}