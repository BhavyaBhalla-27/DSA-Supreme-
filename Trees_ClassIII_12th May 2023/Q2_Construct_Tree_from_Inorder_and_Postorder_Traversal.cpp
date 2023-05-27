#include<iostream>
#include<queue>
#include<unordered_map>
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
// Function to find the root node in the inorder traversal
int findPos(int arr[],int n,int element){
    // Linear search to find the root element
    for(int i = 0;i<n;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
void createMapping(unordered_map<int,int>&mapping,int inorder[],int n){
    for(int i = 0;i<n;i++){
        mapping[inorder[i]] = i;
    }
}
// Function to build the tree from inorder and preorder traversal
Node* buildTree(int inorder[],int postorder[],int size,int &postIndex,int inorderStart,int inorderEnd,unordered_map<int,int>&mapping){
    // Base case
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    // Find root and create node for that
    int element = postorder[postIndex--];
    Node* root = new Node(element);
    // Find position of root element in the inorder 
    // int pos = findPos(inorder,size,element);
    int pos = mapping[element];
    // Solve right subtree first
    root->right = buildTree(inorder,postorder,size,postIndex,pos+1,inorderEnd,mapping);
    // Solve left subtree first
    root->left = buildTree(inorder,postorder,size,postIndex,inorderStart,pos-1,mapping);
    return root;
}
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
int main(){
    int inorder[] = {40,20,10,50,30,60};
    int postOrder[] = {40,20,50,60,30,10};
    int size = 6;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;
    unordered_map<int,int>mapping;
    createMapping(mapping,inorder,size);
    cout<<"Building tree"<<endl;
    Node* root = buildTree(inorder,postOrder,size,postIndex,inorderStart,inorderEnd,mapping);
    cout<<"Printing the tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}