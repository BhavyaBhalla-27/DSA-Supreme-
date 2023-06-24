// https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void dfs(unordered_map<int,bool>&visited,int src,vector<vector<int>>&isConnected){
        visited[src] = true;
        // row -> source and col-> loop
        int size = isConnected[src].size();
        for(int col = 0;col<size;col++){
            // edge is present or not
            if(isConnected[src][col] == 1){
                // col is a neighbour
                if(!visited[col]){
                    dfs(visited,col,isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int count = 0;
        int n = isConnected.size();
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(visited,i,isConnected);
                count++;
            }
        }
        return count;
    }
};