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
int findLength(Node* &head){
    int len = 1;
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtPosition(int data,int position,Node* &head,Node* &tail){
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(position == 0){
        insertAtHead(head,tail,data);
        return;
    }
    int len = findLength(head);
    cout<<len<<endl;
    if(len == position){
        insertAtTail(head,tail,data);
        return;
    }
    // step1 : find the position of prev and curr
    int i = 1;
    Node* prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    // step2 : 
    Node* newNode = new Node(data);
    // step3 :
    newNode -> next = curr;
    // step4 :
    prev->next = newNode;
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
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtPosition(101,5,head,tail);
    print(head);
    return 0;
}