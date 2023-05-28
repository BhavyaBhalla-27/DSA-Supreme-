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
Node* sortedLLIntoBST(Node* &head,int n){
    // Base case
    if(head == NULL || n <= 0 ){ // BST not possible
        return NULL;
    }
    // Getting left subtree
    // Node* leftSubtree = sortedLLIntoBST(head,n-1-n/2);
    Node* leftSubtree = sortedLLIntoBST(head,n/2);
    // Now we can create root as head node now points to the mid node
    Node* root = head;
    // Attach root to left subtree
    root->left = leftSubtree;
    head = head->right;
    // Getting right subtree
    // Head points to one node ahead of mid and hence is updated head
    // root->right = sortedLLIntoBST(head,n/2);
    root -> right = sortedLLIntoBST(head,n-1-n/2);
    return root;
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
void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        // next pointer is right pointer
        temp = temp->right; 
    }
}
void convertToDLL(Node* root,Node* &head){
    // Base case
    if(root == NULL){
        return;
    }
    // Convert right subtree to linked list
    convertToDLL(root->right,head);
    // Attach the root node to right linked list
    root->right = head;
    // Attaching previous pointer
    if(head!=NULL)
        // To avoid NULL pointer exception
        head->left = root;
    // Update head
    head = root;
    // Convert left subtree to linked list
    convertToDLL(root->left,head);
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
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;
    Node* root = bstUsingInorder(inorder,s,e);
    levelOrderTraversal(root);
    Node* head = NULL;
    convertToDLL(root,head);
    cout<<"Printing Sorted Doubly Linked List"<<endl;
    printDLL(head);
    Node* root1 = NULL;
    root1 = sortedLLIntoBST(head,9);
    cout<<endl<<"Doing level order traversal for root 1"<<endl;
    levelOrderTraversal(root1);
    return 0;
}