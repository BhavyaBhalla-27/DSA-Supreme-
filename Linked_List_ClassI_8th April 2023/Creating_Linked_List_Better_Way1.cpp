#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(){
            this->data = 0;
            this->next = NULL;
        }
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
// Insertion at tail case
void insertAtTail(Node* &head,Node* &tail,int data){
    // Empty linked list case
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step - 1
    Node* newNode = new Node(data);
    // Step - 2
    tail->next = newNode;
    // Step - 3
    tail = newNode;
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
int main(){
    Node* head = new Node(10);
    Node* tail = head;
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,30);
    // insertAtHead(head,tail,40);
    // insertAtHead(head,tail,50);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    print(head);
    return 0;
}