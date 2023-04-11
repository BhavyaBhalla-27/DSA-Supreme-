// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
};
    