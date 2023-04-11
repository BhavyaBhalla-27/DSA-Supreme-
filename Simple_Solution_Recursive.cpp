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
Node* reverseList(Node* &prev,Node* &curr){ // Node* data type because we will return the new head
    // Base Case
    if(curr == NULL){
        return prev; // New head is returned
    }
    // 1 case solve
    // Connection of curr to prev
    Node* forward = curr->next; // So that we dont loose the track of the linked list
    curr->next = prev;
    // Recursive equation
    return reverseList(curr,forward); // Updating the pointers prev and curr
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
    Node* prev = NULL;
    Node* curr = head;
    Node* newHead = reverseList(prev,curr);
    printList(newHead);
    return 0;
}