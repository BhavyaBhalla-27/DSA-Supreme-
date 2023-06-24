// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans = grid;
        int ansTime = 0;
        // insert all rotten oranges in queue
        for(int row = 0;row<grid.size();row++){
            for(int col = 0;col<grid[row].size();col++){
                if(grid[row][col] == 2){
                    pair<int,int>coordinate = make_pair(row,col);
                    q.push({coordinate,0});
                }
            }
        }
        // Applying BFS now
        while(!q.empty()){
            auto fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < ans.size() && newY >=0 && newY < ans[0].size() && ans[newX][newY] == 1){
                    pair<int,int>newCoordinate = make_pair(newX,newY);
                    ansTime = max(ansTime,time+1);
                    q.push({newCoordinate,time+1});
                    ans[newX][newY] = 2;
                }
            }
        }
        // Handling fresh orange remaining
        for(int i = 0;i<ans.size();i++){
            for(int j = 0;j<ans[i].size();j++){
                if(ans[i][j] == 1){
                    return -1;
                }
            }
        }
        return ansTime;
    }
    
};