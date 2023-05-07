// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    void solve(TreeNode* root,int targetSum,int currSum,vector<int>&path,vector<vector<int>>&ans){
        // base case
        if(root == NULL){
            return;
        }
        // leaf node
        if(root -> left == NULL && root->right == NULL){
            // include leaf node in the sum
            path.push_back(root->val);
            currSum += root->val;
            if(currSum == targetSum){
                ans.push_back(path);
            }
            path.pop_back();
            currSum -= root->val;
            return;
        }
        // include current node
        path.push_back(root->val);
        currSum += root->val;
        solve(root->left,targetSum,currSum,path,ans);
        solve(root->right,targetSum,currSum,path,ans);
        // backtrack due to by reference
        path.pop_back();
        currSum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum = 0;
        vector<int>target;
        solve(root,targetSum,sum,target,ans);
        return ans;
    }
};