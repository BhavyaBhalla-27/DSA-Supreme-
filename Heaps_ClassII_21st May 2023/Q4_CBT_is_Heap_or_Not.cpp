#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
pair<bool,int>solve(Node* root){
    // Base Case
    if(root == NULL){
        pair<bool,int>p = make_pair(true,INT_MIN);
        return p;
    }
    // Leaf Node
    if(root->left == NULL && root->right == NULL){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    // Solve for left and right subtree
    pair<bool,int> leftAns = solve(root->left);
    pair<bool,int> rightAns = solve(root->right);
    // Check the conditions
    if(leftAns.first && rightAns.first && root->data > leftAns.second && root->data > rightAns.second){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    else{
        pair<bool,int>p = make_pair(false,root->data);
        return p;
    }
}
int main(){

    return 0;
}