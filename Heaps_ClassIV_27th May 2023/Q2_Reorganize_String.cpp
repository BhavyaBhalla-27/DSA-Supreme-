// https://leetcode.com/problems/reorganize-string/submissions/959596416/

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
    string reorganizeString(string s) {
        // Create the mapping
        int freq[26] = {0};
        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }
            // Now create a max heap
            priority_queue<node,vector<node>,compare>maxHeap;
        // Insert the elements in the max heap
        for(int i = 0;i<26;i++){
            if(freq[i] != 0){
                node temp(i+'a',freq[i]);
                maxHeap.push(temp);
            }
        }
        string ans = "";
        while(maxHeap.size() > 1){
            // Fetch top 2 element
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();
            ans = ans + first.data;
            ans = ans + second.data;
            first.count--;
            second.count--;
            // Push in heap if count is not 0
            if(first.count!=0){
                maxHeap.push(first);
            }
            if(second.count!=0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count == 1){
                ans = ans + temp.data;
            }
            else{
                // adjacent can come
                ans = "";
            }
        }
        return ans;
    }
};






