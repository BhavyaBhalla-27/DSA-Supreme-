#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree(int data)
{
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);
    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);
    return root;
}
int height(Node* root){
    // base case -> empty tree has height 0
    if(root == NULL){
        return 0;
    }
    // left tree height
    int leftHeight = height(root->left);
    // right tree height
    int rightHeight = height(root->right);
    // max of left subtree and right subtree and +1 to consider the root node
    int ans = max(leftHeight,rightHeight) + 1;
    // return the height 
    return ans;
}
int diameterBinaryTree(Node* root){
    // Base case -> empty tree
    if(root == NULL){
        return 0;
    }
    // left subtree check
    int op1 = diameterBinaryTree(root->left);
    // right subtree check
    int op2 = diameterBinaryTree(root->right);
    // case when root node is included in the answer
    int op3 = height(root->left) + height(root->right);
    // we have to choose the longest path and hence max is taken
    int ans = max(op1,max(op2,op3));
    // return diameter
    return ans;
}
int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    diameterBinaryTree(root);
    return 0;
}
