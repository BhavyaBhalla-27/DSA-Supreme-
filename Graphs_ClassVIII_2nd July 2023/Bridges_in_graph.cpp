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
    unordered_map<int,list<int>>adjList;
    void addEdge(int u,int v,bool direction){
        // direction = 1 -> undirected
        // direction = 0 -> directed
        adjList[u].push_back(v);
        if(direction == 1){
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j<<","<<j<<"), ";
            }
            cout<<endl;
        }
    }
    void findBridges(int src,int parent,int &timer,vector<int>&tin,vector<int>&low,unordered_map<int,bool>&visited){
        timer++;
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        for(auto nbr : adjList[src]){
            // We don't have to update low if nbr is a parent
            if(nbr == parent)
                continue;
            if(!visited[nbr]){
                // dfs call
                findBridges(nbr,src,timer,tin,low,visited);
                // low update
                low[src] = min(low[src],low[nbr]);
                // check for bridge (Here I will do the mistake)
                if(low[nbr] > tin[src])
                    cout<<nbr<<"--"<<src<<" is a bridge"<<endl;
            }
            else{
                // node is visited and not parent
                // low update
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
	

};

int main(){
    Graph g;
    g.addEdge(1,0,1);
    g.addEdge(1,2,1);
    g.addEdge(2,0,1);
    g.addEdge(0,3,1);
    g.addEdge(3,4,1);
    int n = 5;
    int timer = 0;
    vector<int>tin(n);
    vector<int>low(n);
    unordered_map<int,bool>visited;
    g.findBridges(0,-1,timer,tin,low,visited);
    
    return 0;
}