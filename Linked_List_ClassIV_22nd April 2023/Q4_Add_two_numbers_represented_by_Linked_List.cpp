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
Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node* add(Node* &head1,Node* &head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    // Step 1 Reverse both the linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);
    // Step 2 Add both the linked lists
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while(head1!=NULL && head2!=NULL){
        // Find sum
        int sum = carry + head1->data + head2->data;
        // Find digit
        int digit = sum%10;
        // Find carry
        carry = sum/10;
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            // First node insert
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }
    // Handle the carry
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }
    // Step 3 Reverse the Linked List
    ansHead = reverse(ansHead);
    return ansHead;
}
int main(){
    Node* head1 = new Node(2);
    Node* first = new Node(4);
    head1->next = first;
    
    Node* head2 = new Node(2);
    Node* first1 = new Node(3);
    Node* second1 = new Node(4);
    head2->next = first1;
    first1->next = second1;

    Node* newHead = add(head1,head2);

    print(newHead);
    return 0;
}