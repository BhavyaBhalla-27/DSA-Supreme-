// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        // Base case
        if(root == NULL){
            return -1;
        }
        // Inorder traversal
        // Left 
        int leftAns = kthSmallest(root->left,k);
        // Valid answer
        if(leftAns != -1){
            return leftAns;
        }
        // Node
        k--;
        if(k == 0){
            return root->val;
        }
        // Right
        int rightAns = kthSmallest(root->right,k);
        return rightAns;
    }
};