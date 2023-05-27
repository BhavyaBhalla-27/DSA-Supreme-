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
// Function to build the tree from inorder and preorder traversal
Node* buildTree(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd,unordered_map<int,int>&mapping){
    // Base case
    if(preIndex >= size || inorderStart > inorderEnd){
        // Insert NULL
        return NULL;
    }
    // Find the root node of the tree and we get this from preorder traversal
    int element = preorder[preIndex++];
    // Create root node for this element
    Node* root = new Node(element);
    // Find the root element in the inorder
    // int pos = findPos(inorder,size,element);
    int pos = mapping[element];
    // Solving left part
    root->left = buildTree(inorder,preorder,size,preIndex,inorderStart,pos-1,mapping);
    // Solving right part
    root->right = buildTree(inorder,preorder,size,preIndex,pos+1,inorderEnd,mapping);
    // return root node 
    return root;
}
void createMapping(unordered_map<int,int>&mapping,int inorder[],int n){
    for(int i = 0;i<n;i++){
        mapping[inorder[i]] = i;
    }
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
    int inorder[] = {3,1,4,5,2};
    int preorder[] = {5,1,3,4,2};
    int size = 5;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;
    unordered_map<int,int>mapping;
    createMapping(mapping,inorder,size);
    cout<<"Building tree"<<endl;
    Node* root = buildTree(inorder,preorder,size,preIndex,inorderStart,inorderEnd,mapping);
    cout<<"Printing the tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}