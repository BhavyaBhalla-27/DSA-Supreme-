// https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case -> Think later
        if(head == NULL || head->next == NULL){
            cout<<"Empty Linked List"<<endl;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
    
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};