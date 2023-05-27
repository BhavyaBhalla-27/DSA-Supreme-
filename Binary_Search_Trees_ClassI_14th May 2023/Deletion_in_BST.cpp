#include <iostream>
#include <queue>
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
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBST(Node *root, int data)
{
    // Empty tree
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if (root->data > data)
    {
        // insert into left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
// To print the tree level wise
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *findNode(Node *root, int target)
{
    // Base case
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    // Left
    else if (root->data > target)
    {
        return findNode(root->left, target);
    }
    // Right
    else
    {
        return findNode(root->right, target);
    }
}
int findMax(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
Node *deleteNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == target)
    {
        // Case 1 : Leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        // Case 2 : Left child not exist
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            return child;
        }
        // Case 3 : Right child not exist
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            return child;
        }
        // Case 4 : Both child exists
        else
        {
            int inorderPred = findMax(root->left);
            root->data = inorderPred;
            root->left = deleteNodeInBST(root->left, inorderPred);
            return root;
        }
    }
    else if (root->data < target)
    {
        // right
        root->right = deleteNodeInBST(root->right, target);
    }
    else
    {
        // left
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node" << endl;
    takeInput(root);
    deleteNodeInBST(root, 100);
    levelOrderTraversal(root);
    return 0;
}