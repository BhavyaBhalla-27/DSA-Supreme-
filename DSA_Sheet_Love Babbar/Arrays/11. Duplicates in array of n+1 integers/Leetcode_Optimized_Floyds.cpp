class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 0th index wont be pointed by anyone as the numbers lie between 1 to n
        int slow = 0;
        int fast = 0;
        // Find intersection of fast and slow
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // Move slow pointer again to 0 and then increment fast by 1 and slow by 1 and find the 
        // intersection
        slow = 0;  
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        } 
        return slow;
    }
};