class node{
    public:
        int data;
        int row;
        int col;
        node(int d,int r,int c){
            data = d;
            row = r;
            col = c;
        }
};
class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        // Creation of min heap
        priority_queue<node*,vector<node*>,compare>minHeap;
        // Insert first elements of all the k lists
        int k = nums.size();
        for(int i = 0;i<k;i++){
            int element = nums[i][0];
            maxi = max(maxi,element);
            mini = min(mini,element);
            minHeap.push(new node(element,i,0));
        }
        int ansStart = mini;
        int ansEnd = maxi;
        while(!minHeap.empty()){
            // fetch top element
            node* top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            // pop the top element
            minHeap.pop();
            // the element popped will be the minimum element
            mini = topElement;
            // Check for answer
            if(maxi-mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }
            // check whether element exists in the list 
            if(topCol + 1 < nums[topRow].size()){
                // exists
                // create a new node and insert
                // update maxi as we are inserting new node
                maxi = max(maxi,nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol + 1],topRow,topCol+1);
                minHeap.push(newNode);
            }
            else{
                // not exists
                break;
            }
        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};