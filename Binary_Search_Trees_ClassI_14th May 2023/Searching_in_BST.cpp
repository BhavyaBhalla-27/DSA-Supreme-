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
Node* insertIntoBST(Node* root,int data){
    // Empty tree
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if(root->data > data){
        // insert into left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        // insert into right
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
bool findNode(Node* root,int target){
    // Base case
    if(root == NULL)
        return false;
    if(root->data == target)
        return true;
    // Left
    else if(root->data > target){
        return findNode(root->left,target);
    }
    // Right
    else{
        return findNode(root->right,target);
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);
    if(findNode(root,1000)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}