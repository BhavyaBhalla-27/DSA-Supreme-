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
class NodeData{
    public:
        int size;
        int minVal;
        int maxVal;
        bool validBST;
        NodeData(){

        }
        NodeData(int size,int max,int min,bool valid){
            this->size = size;
            minVal = min;
            maxVal = max;
            validBST = valid;
        }
};
NodeData findLargestBST(Node* root,int &ans){
    // Base Case
    if(root == NULL){
        NodeData temp(0,INT_MIN,INT_MAX,true);
        return temp;
    }
    // First find left subtree answer
    NodeData leftAns = findLargestBST(root->left,ans);
    // Then find right subtree answer
    NodeData rightAns = findLargestBST(root->right,ans);
    // Checking starts here
    NodeData currNode;
    currNode.size = leftAns.size + rightAns.size + 1;
    currNode.maxVal = max(root->data,rightAns.maxVal);
    currNode.minVal = min(root->data,leftAns.minVal);
    // Left , Right and Current node is a BST
    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNode.validBST = true;
    }
    else{
        currNode.validBST = false;
    }
    if(currNode.validBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
}
int main(){
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    int ans = 0;
    findLargestBST(root,ans);
    cout<<"Largest BST size = "<<ans<<endl;
    return 0;
}