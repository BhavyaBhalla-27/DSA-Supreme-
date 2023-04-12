#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = this;
        }
        ~Node(){
            int val = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory free for node with value = "<<val<<endl;
        }
};
int findLength(Node* &head){
    int len = 1;
    Node* temp = head;
    while(temp->next != head){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Creation of new Node
    Node* temp = new Node(data);
    // Connection step
    tail->next = temp;
    temp->next = head;
    // Update head
    head = temp;
}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    // Creation 
    Node* newNode = new Node(data);
    // Connection step
    tail->next = newNode;
    newNode->next = head;
    // Update tail
    tail = newNode;
}
void insertAtPosition(Node* &head,Node*& tail,int data,int pos){
    // Here the concept of one pointer we have to use 
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    if(pos == 0){
        insertAtHead(head,tail,data);
        return;
    }
    int len = findLength(head);
    cout<<len<<endl;
    if(len == pos){
        insertAtTail(head,tail,data);
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
void deleteHead(Node* &head,Node* &tail){
    if(head == NULL){
        return;
    }
    Node* temp = head; 
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    delete temp;
}
void deleteTail(Node* &head,Node* &tail){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp->next!=tail){
        temp = temp->next;
    }
    Node* temp1 = tail;
    temp->next = head;
    tail->next = NULL;
    tail = temp;
    delete temp1;
}
void deleteOperation(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty";
        return;
    }
    // Head node deletion
    if(position == 0)
    {
        deleteHead(head,tail);
        return;
    }
    // Tail node deletion
    int len = findLength(head);
    if(position >= len){
        deleteTail(head,tail);
        return;
    }
    // step  : find prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step2:
    prev->next = curr->next;
    // step3:
    curr->next = NULL;
    // step4:
    delete curr;
}
void printList(Node* &head){
    Node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
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
    insertAtPosition(head,tail,35,3);
    cout<<findLength(head)<<endl;
    // deleteHead(head,tail);
    // deleteTail(head,tail);
    deleteOperation(6,head,tail);
    printList(head);
    return 0;
}