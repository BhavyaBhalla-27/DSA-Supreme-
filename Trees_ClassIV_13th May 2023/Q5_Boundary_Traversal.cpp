#include <iostream>
#include <queue>
#include<vector>
#include<map>

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
void printLeftNodes(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // Leaf node (we have to stop)
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // Print current node and go to left
    cout<<root->data<<" ";
    if(root->left)
        printLeftNodes(root->left);
    // if left nodes does not exist
    else
        printLeftNodes(root->right);
}
void printLeafNodes(Node* root){
    if(root == NULL){
        return;
    }
    // leaf node found
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}
void printRightNodes(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // Leaf node (we have to stop)
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // Right call first
    if(root->right)
        printRightNodes(root->right);
    // Left call 
    else
        printRightNodes(root->left);
    // While returing print the nodes
    cout<<root->data<<" ";
}
// Boundary Traversal
void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // First print the root node so that duplicacy is not there
    cout<<root->data<<" ";
    // Print left nodes
    printLeftNodes(root->left);
    // Print leaf nodes
    printLeafNodes(root);
    // Print right nodes in reverse order
    printRightNodes(root->right);
}
// 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1
int main()
{
    Node* root = buildTree(10);
    boundaryTraversal(root);
    return 0;
}