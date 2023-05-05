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
int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    return 0;
}