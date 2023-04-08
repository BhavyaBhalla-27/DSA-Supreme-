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
int main(){
    // Creation of Nodes of Linked list
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    // Connecting them
    first->next = second;
    second->next = third;
    
    return 0;
}