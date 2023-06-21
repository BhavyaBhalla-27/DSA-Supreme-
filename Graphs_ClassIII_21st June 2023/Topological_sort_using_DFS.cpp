#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class Graph{
    public:
        unordered_map<T,list<T>>adjList;
        void addEdge(T u,T v,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            // Create an edge from u to v
            adjList[u].push_back(v);
            // if undirected 
            if(direction == 0)
                adjList[v].push_back(u); // edge created from v to u    
        }
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }
        void topoSort(int src,unordered_map<int,bool>&visited,stack<int>&ans){
            
            visited[src] = true;
            for(auto neighbour : adjList[src]){
                if(!visited[neighbour]){
                    topoSort(neighbour,visited,ans);
                }
            }
            // while returing store node in stack
            ans.push(src);
        }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    stack<int>ans;
    unordered_map<int,bool>visited;
    for(int i = 0;i<8;i++){
        if(!visited[i]){
            g.topoSort(i,visited,ans);
        }
    }
    // Print the topological sort
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}