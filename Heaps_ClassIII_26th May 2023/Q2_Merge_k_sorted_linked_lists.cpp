// https://leetcode.com/problems/merge-k-sorted-lists/

class compare{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
}; 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a min heap
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;
        // Insert k pointer (first node's pointer of each linked list)
        int k = lists.size();
        // No linked list then can't merge
        if(k == 0)
            return NULL;
        for(int i = 0; i<k;i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            // Step 1 : Fetch the top element of heap
            ListNode* temp = minHeap.top();
            minHeap.pop();
            // Step 2 : Insert the top element in the ans vector
            // First element insert ? 
            if(head == NULL){
                head = temp;
                tail = temp;
                // Step 3 : Insert further elements
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
            else{
                // temp is not the first element in ans
                tail->next = temp;
                tail = temp;
                // Step 3 : Insert further elements
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
            
        }
        return head;
    }
};