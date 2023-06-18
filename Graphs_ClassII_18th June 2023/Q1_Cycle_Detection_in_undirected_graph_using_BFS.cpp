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
        bool checkCycle(int src,unordered_map<int,bool>&visited){
            queue<int>q;
            unordered_map<int,int>parent;
            q.push(src);
            visited[src] = true;
            parent[src] = -1;
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                for(auto neighbour : adjList[frontNode]){
                    if(!visited[neighbour]){
                        // Simply push in queue and set visited and parent
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = frontNode;
                    }
                    else{
                        // already visited
                        if(neighbour != parent[frontNode]){
                            // cycle present
                            return true;
                        }
                    }
                }
            }
            return false;
        }
};
int main(){
    Graph<int>g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);
    int n = 5;
    bool ans = false;
    unordered_map<int,bool>visited;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            ans = g.checkCycle(i,visited);
            if(ans == true)
                break;
        }
    }
    if(ans == true)
        cout<<"Cycle is present";
    else    
        cout<<"Cycle not present";
    return 0;
}