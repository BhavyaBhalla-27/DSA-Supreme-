// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Create a max heap
        priority_queue<int>maxHeap;
        // Push the elements in max heap
        for(int i = 0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }
        // Now perform the operations for k times
        while(k--){
            // Fetch top element
            int topElement = maxHeap.top();
            // Remove that element
            maxHeap.pop();
            // Reduce the top element 
            topElement = topElement - topElement/2;
            // Push the topElement in maxHeap again
            maxHeap.push(topElement);
        }
        // Sum of the max heap elements
        int sum = 0;
        while(!maxHeap.empty()){
            int element = maxHeap.top();
            sum = sum + element;
            maxHeap.pop();
        }
        return sum;
    }
};