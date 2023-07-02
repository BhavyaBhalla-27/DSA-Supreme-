// https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
public:
    void findBridges(int src,int parent,int &timer,vector<int>&tin,vector<int>&low,unordered_map<int,bool>&visited,vector<vector<int>>&ans,unordered_map<int,list<int>>&adjList){
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
                findBridges(nbr,src,timer,tin,low,visited,ans,adjList);
                // low update
                low[src] = min(low[src],low[nbr]);
                // check for bridge
                if(low[nbr] > tin[src]){
                    vector<int>temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
                    
            }
            else{
                // node is visited and not parent
                // low update
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adjList;
        for(int i = 0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<vector<int>>ans;
        int timer = 0;
        vector<int>tin(n);
        vector<int>low(n);
        unordered_map<int,bool>visited;
        findBridges(0,-1,timer,tin,low,visited,ans,adjList);
        return ans;
    }
};