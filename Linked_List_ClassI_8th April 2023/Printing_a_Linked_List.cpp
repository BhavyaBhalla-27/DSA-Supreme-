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
    // Creation of Nodes of Linked list
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    // Connecting them
    first->next = second;
    second->next = third;
    // Printing linked list
    print(first);
    return 0;
}