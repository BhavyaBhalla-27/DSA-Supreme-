#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
// Insertion at head case
void insertAtHead(Node* &head,Node* &tail,int data){
    // Empty Linked list case
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step - 1
    Node* newNode = new Node(data);
    // Step - 2
    newNode->next = head;
    // Step - 3
    head = newNode;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){ // Step - 3 Stop when we reach NULL
        // Step - 1 Print
        cout<<temp->data<<" ";
        // Step - 2 Move temp to next
        temp = temp->next;
    }
}
// Recursive approach
Node* reverseRecursive(Node* &prev,Node* &curr){
    // Base case
    if(curr == NULL){
        return prev; // New head
    }
    // 1 case solve
    Node* forward = curr->next;
    curr->next = prev;
    // recursive call
    return reverseRecursive(curr,forward);
}
// Loop approach
Node* reverseIterative(Node* &prev , Node* &curr){
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    print(head);
    cout<<endl;
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    // Node* newHead = reverseRecursive(prev,curr);
    Node* newHead = reverseIterative(prev,curr);
    print(newHead);
    return 0;
}