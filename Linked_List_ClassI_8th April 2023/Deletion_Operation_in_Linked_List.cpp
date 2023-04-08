#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Deleted value" << this->data;
    }
};
int findLength(Node *&head)
{
    int len = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
// Insertion at tail case
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Empty linked list case
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step - 1
    Node *newNode = new Node(data);
    // Step - 2
    tail->next = newNode;
    // Step - 3
    tail = newNode;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    { // Step - 3 Stop when we reach NULL
        // Step - 1 Print
        cout << temp->data << " ";
        // Step - 2 Move temp to next
        temp = temp->next;
    }
}
void deleteOperation(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete, LL is empty";
        return;
    }

    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);

    // deleting last node
    if (position == len)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step2:
        prev->next = NULL;
        // step3:
        Node *temp = tail;
        // step4:
        tail = prev;
        // step5:
        delete temp;
        return;
    }

    // deleting middle node

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
int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    deleteOperation(5,head,tail);
    cout<<endl;
    print(head);

    return 0;
}