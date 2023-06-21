#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
        void topoSort(int n,vector<int>&ans){
            queue<int>q;
            unordered_map<int,int>indegree;
            // Calculate indegree
            for(auto i : adjList){
                int src = i.first;
                for(auto nbr : i.second){
                    indegree[nbr]++;
                }
            }
            // Put nodes in queue having indegree = 0;
            for(int i = 0;i<n;i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            // BFS logic
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode);
                for(auto nbr : adjList[frontNode]){
                    // As nodes are removed from graph
                    indegree[nbr]--;
                    // check for 0 indegree again
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
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
    int n = 8;
    vector<int>ans;
    // connected or disconnected 
    g.topoSort(n,ans);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}