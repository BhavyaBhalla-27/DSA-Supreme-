// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void dfs(int x,int y,int oldColor,int newColor,map<pair<int,int>,bool>&visited,vector<vector<int>>&ans){
        visited[{x,y}] = true;
        ans[x][y] = newColor;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < ans.size() && newY >= 0 and newY < ans[0].size() && !visited[{newX,newY}] && ans[newX][newY]==oldColor){
                dfs(newX,newY,oldColor,newColor,visited,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        map<pair<int,int>,bool>visited;
        vector<vector<int>>ans = image;
        dfs(sr,sc,oldColor,color,visited,ans);
        return ans;
    }
};