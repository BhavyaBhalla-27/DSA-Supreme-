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
        bool checkCycle(int src,unordered_map<int,bool>&visited,int parent){
            visited[src] = true;
            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    bool checkAns = checkCycle(nbr,visited,src);
                    if(checkAns == true)
                        return true;
                }
                else{
                    if(nbr!=parent){
                        // cycle is present
                        return true;
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
            ans = g.checkCycle(i,visited,-1);
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