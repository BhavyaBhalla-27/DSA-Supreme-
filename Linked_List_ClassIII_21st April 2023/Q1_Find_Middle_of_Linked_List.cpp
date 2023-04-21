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
Node* getMiddle(Node* &head){
    // If empty linked list
    if(head == NULL){
        cout<<"Linked List is empty";
        return head;
    }
    // Only one node in the linked list
    if(head -> next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head; // n/2 + 1 will be the answer
    // Node* fast = head->next;  // If we want n/2 as the answer
    // slow and fast are valid
    while(slow!=NULL && fast!=NULL){
        fast = fast->next; // move 1 step
        if(fast!=NULL){ // check if fast becomes null
            fast = fast->next; // if not null, then simply move 1 step more and hence in total 2 steps
            slow = slow->next; // move 1 step
        }
    }
    return slow; // return slow which will be the middle node
}
int main(){
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    head->next = first;
    first->next = second;
    second->next = third;
    Node* middle = getMiddle(head);
    cout<<"Middle node = "<<middle->data<<" ";
    return 0;
}