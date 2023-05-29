// https://leetcode.com/problems/longest-happy-string/description/

class node{
    public:
        char data;
        int count;
        node(char d,int c){
            data = d;
            count = c;
        }
};
class compare{
    public:
        bool operator()(node a,node b){
            return a.count < b.count;
        }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Now create a max heap
        priority_queue<node,vector<node>,compare>maxHeap;
        // Insert enteries in the max heap
        if(a > 0){
            node temp('a',a);
            maxHeap.push(temp);
        }
        if(b > 0){
            node temp('b',b);
            maxHeap.push(temp);
        }
        if(c > 0){
            node temp('c',c);
            maxHeap.push(temp);
        }
        string ans = "";
        // Do processing until maxHeap has size > 1
        while(maxHeap.size()>1){
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();
            // Try to get 2 characters from first
            if(first.count >= 2){
                ans+=first.data;
                ans+=first.data;
                first.count-=2;
            }
            // If count is not 2, then it is 1
            else{
                ans+=first.data;
                first.count--;
            }
            // Try to get 2 characters from second
            if(second.count >= 2 && second.count>=first.count){
                ans+=second.data;
                ans+=second.data;
                second.count-=2;
            }
            // If count is not 2, then it is 1
            else{
                ans+=second.data;
                second.count--;
            }
            // Push first if count > 0
            if(first.count > 0){
                maxHeap.push(first);
            }
            if(second.count > 0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();
            // Try to get 2 characters from temp
            if(temp.count >= 2){
                ans+=temp.data;
                ans+=temp.data;
                temp.count-=2;
            }
            // If count is not 2, then it is 1
            else{
                ans+=temp.data;
                temp.count--;
            }
        }
        return ans;
    }
};