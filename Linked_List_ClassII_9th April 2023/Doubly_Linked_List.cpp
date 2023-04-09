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
int main(){
    Node* head = new Node(10);
    Node* first = new Node(20);
    head->next = first;
    first->prev = head;
    print(head);
    cout<<endl;
    cout<<"Length = "<< getLength(head);
    return 0;
}