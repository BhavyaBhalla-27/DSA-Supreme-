// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

class Solution {
public:
    void storeInorder(TreeNode* root,vector<int>&inorder){
        if(root == NULL){
            return;
        }
        // Left
        storeInorder(root->left,inorder);
        // Node
        inorder.push_back(root->val);
        // Right
        storeInorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        storeInorder(root,inorder);
        // 2 pointer approach
        int s = 0;
        int e = inorder.size() - 1;
        while(s < e){
            int sum = inorder[s] + inorder[e];
            if(sum == k){
                return true;
            }
            else if(sum > k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};