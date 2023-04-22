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
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void removeDuplicates(Node* &head){
    // Empty Linked List
    if(head == NULL){
        return;
    }
    if(head -> next == NULL){
        return;
    }
    Node* curr = head;
    while(curr!=NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            // Delete 
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
}
int main(){
    Node* head = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(4);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    cout<<"Input Linked List "<<endl;
    print(head);
    removeDuplicates(head);
    cout<<"Output Linked List "<<endl;
    print(head);
    return 0;
}