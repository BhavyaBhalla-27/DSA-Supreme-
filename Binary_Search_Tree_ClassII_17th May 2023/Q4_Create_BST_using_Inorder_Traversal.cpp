#include<iostream>
#include<queue>
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
Node *bstUsingInorder(int inorder[],int s,int e){
    // Base Case
    if(s>e){
        return NULL; // Invalid array and hence NULL tree
    }
    // Find middle node
    int mid = s + (e-s)/2;
    int element = inorder[mid];
    Node* root = new Node(element);
    // Left subtree creation
    root->left = bstUsingInorder(inorder,s,mid-1);
    // Right subtree creation
    root->right = bstUsingInorder(inorder,mid+1,e);
    return root;
}
int main(){
    int inorder[] = {10,20,30,40,50,60,70,80,90};
    int s = 0;
    int e = 8;
    Node* root = bstUsingInorder(inorder,s,e);
    levelOrderTraversal(root);
    return 0;
}