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
    void dijkstraAlgo(int src,int n){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
        while(!st.empty()){
            // Fetch the smallest or first element from set
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            // pop from set
            st.erase(st.begin());
            // Traverse neighbour
            for(auto nbr : adjList[node]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    // update distance
                    // finding entry in the set
                    auto result = st.find({dist[nbr.first],nbr.first});
                    // if found -> delete 
                    if(result != st.end()){
                        st.erase(result);
                    }
                    // update in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert({dist[nbr.first],nbr.first});
                }
            }
        }
        cout<<"Printing array"<<endl;
        for(int i = 0;i<n;i++){
            cout<<dist[i]<<" ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(6,5,9,0);
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,4,11,0);
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,15,0);
    g.addEdge(5,4,6,0);
    int n = 7;
    int src = 6;
    g.dijkstraAlgo(src,n);
    return 0;
}