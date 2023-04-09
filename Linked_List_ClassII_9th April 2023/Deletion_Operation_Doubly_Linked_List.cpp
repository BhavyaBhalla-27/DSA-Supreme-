#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev; // previous pointer
        Node* next; // next pointer
        // Default Constructor
        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        // Parameterized Constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
        ~Node(){
            cout<<"Deleted data with value = "<<this->data<<endl;
        }
};
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int getLength(Node* &head){
    Node* temp = head;
    int len = 1;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Normal steps to be followed
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;

}
void deleteOperation(Node* &head,Node* &tail,int pos){
    // Deleting head
    int len = getLength(head);
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    // Deleting tail
    if(pos >= len){
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    // Deleting position
    int i = 1;
    Node* left = head;
    while(i < pos - 1){
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}
int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    deleteOperation(head,tail,2);
    print(head);
    return 0;
}