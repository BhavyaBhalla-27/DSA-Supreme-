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
int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    cout<<"Height of Binary Tree = "<<height(root)<<endl;
    return 0;
}