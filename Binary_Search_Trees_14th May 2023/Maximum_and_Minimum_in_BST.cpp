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
int findMin(Node* root){
    Node* temp = root;
    if(temp == NULL)
        return -1;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}
int findMax(Node* root){
    Node* temp = root;
    if(temp == NULL)
        return -1;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data for Node"<<endl;
    takeInput(root);
    int minValue = findMin(root);
    cout<<"Minimum value = "<<minValue<<endl;
    int maxValue = findMax(root);
    cout<<"Maximum value = "<<maxValue<<endl;
    return 0;
}