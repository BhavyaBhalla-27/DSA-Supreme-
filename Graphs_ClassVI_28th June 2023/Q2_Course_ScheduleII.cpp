// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
     void topoSort(int n,unordered_map<int,list<int>>&adjList,vector<int>&ans){
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
            // We need to return empty array if not a valid topological sort
            if(ans.size() != n)
                ans = {};

        }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        unordered_map<int,list<int>>adjList;
        for(auto task : prerequisites){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        topoSort(numCourses,adjList,ans);
        return ans;
        
    }
};