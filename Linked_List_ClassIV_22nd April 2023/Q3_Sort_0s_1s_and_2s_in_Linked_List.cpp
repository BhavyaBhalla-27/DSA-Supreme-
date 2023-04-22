#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*
Approach - 1

void sortLinkedList(Node *&head)
{
    // Step 1 -> Count
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
        temp = temp->next;
    }
    // Step 2 -> Fill 0s 1s and 2s
    temp = head;
    // Fill zeroes
    while (zeroCount--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    // Fill ones
    while (oneCount--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    // Fill two
    while (twoCount--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}
*/

// Approach 2 (Dummy node)
Node* sortLinkedList(Node* &head){
    // Creation of dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    // Traverse original linked list
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data == 0){
            // Seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the zero node
            zeroTail -> next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1){
            // Seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the one node
            oneTail -> next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2){
             // Seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the two node
            twoTail -> next = temp;
            twoTail = temp;
        }
    }
    // Join them and delete dummy nodes

    // Modify oneHead Linked List
    Node* temp = oneHead;
    oneHead = oneHead -> next;
    temp->next = NULL;
    delete temp;
    // Modify twoHead Linked List
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;
    // Join List
    if(oneHead!=NULL){
        // oneHead Linked List is non-empty
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        // oneHead Linked List is empty this means

        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }
    // Remove zeroHead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;
    // return head
    return zeroHead;
}
int main()
{
    Node *head = new Node(0);
    Node *first = new Node(2);
    Node *second = new Node(0);
    Node *third = new Node(2);
    Node *fourth = new Node(0);
    Node *fifth = new Node(2);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    cout << "Before sorting" << endl;
    print(head);
    cout<<endl;
    head = sortLinkedList(head);
    cout << "After sorting" << endl;
    print(head);
    return 0;
}