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
        ~Node(){
            int val = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free of node with value = "<<val<<endl;
        }
};
void insertAtHead(Node* &head,int data){
    // Empty Linked List Case
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node* &head,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    // Traverse till the tail
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    // Now we have got tail as the temp
    Node* newNode = new Node(data);
    temp->next = newNode;
}
int findLength(Node* &head){
    Node* temp = head;
    int len = 1;
    while(temp->next!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtPosition(Node* &head,int data,int pos){
    // Here the concept of one pointer we have to use 
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    if(pos == 0){
        insertAtHead(head,data);
        return;
    }
    int len = findLength(head);
    cout<<len<<endl;
    if(len == pos){
        insertAtTail(head,data);
        return;
    }
    // step1 : find the position of prev and curr
    int i = 1;
    Node* prev = head;
    while(i<pos){
        prev = prev->next;
        i++;
    }
    // Creation of new Node
    Node* newNode = new Node(data);
    newNode -> next = prev->next;
    prev->next = newNode;
}
void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(10);
    // insertAtHead(head,20);
    // insertAtHead(head,30);
    // insertAtHead(head,40);
    // insertAtHead(head,50);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    insertAtPosition(head,25,1);
    printList(head);
    return 0;
}