#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
// creation of linked list
void insertAtTail(Node* &head,Node* &tail,int data){
    // empty linked list case
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return; 
    }
    // creation of new node
    Node* newNode = new Node(data);
    // connection
    tail->next = newNode;
    // updating tail
    tail = newNode;
}
void printList(Node*&head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
// reverse a linked list
Node* reverseList(Node* &head){ // Node* data type because we will return the new head
    // Base case -> Think later
    if(head == NULL){
        cout<<"Empty Linked List"<<endl;
        return head;
    }
    // Mainitaining two pointers prev and curr
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr!=NULL){
        // 3rd pointer maintained to have the track of remaining linked list
        Node* forward = curr->next;
        curr->next = prev; // Connecting to previous node
        prev = curr; // Updating prev node after connection 
        curr = forward; // Updating curr node
    }
    return prev; // new head will be previous node
}
int main(){
    Node* head = NULL;
    Node* tail = head;
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    printList(head);
    cout<<endl;
    Node* newHead = reverseList(head);
    printList(newHead);
    return 0;
}