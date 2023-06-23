#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
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
    void shortestPath(int src,int dest){
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        // initial steps for src
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                }
            }
        }
        // Parent array is ready now
        vector<int>ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        // reverse the ans
        reverse(ans.begin(),ans.end());
        for(auto i : ans){
            cout<<i<<" ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1,1);
    g.addEdge(0,2,1,1);
    g.addEdge(0,3,1,1);
    g.addEdge(1,4,1,1);
    g.addEdge(4,5,1,1);
    g.addEdge(2,5,1,1);
    g.addEdge(3,6,1,1);
    g.addEdge(6,5,1,1);
    g.printAdjList();
    int src = 0;
    int dest = 5;
    cout<<"Printing shortest path"<<endl;
    g.shortestPath(src,dest);
    return 0;
}