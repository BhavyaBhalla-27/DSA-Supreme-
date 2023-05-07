// https://leetcode.com/problems/balanced-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int height(TreeNode* root){
        // Base case -> Empty tree
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        int ans = 1 + max(lh,rh);
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // Base case -> Tree is empty
        if(root == NULL){
            return true;
        }
        // Solve 1 case
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 = (diff<=1);
        // Recursion will handle
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        if(ans1&&leftAns&&rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};