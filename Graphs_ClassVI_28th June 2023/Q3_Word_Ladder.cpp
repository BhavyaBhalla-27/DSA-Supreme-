// https://leetcode.com/problems/word-ladder/description/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        // Whichever node I am inserting in queue needs to be deleted
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int>fNode = q.front();
            q.pop();
            string currString = fNode.first;
            int currCount = fNode.second;
            // Check whether we reached endWord or not
            if(currString == endWord){
                return currCount;
            }
            for(int index = 0;index<currString.length();index++){
                char originalChar = currString[index];
                // Replace character from a to z
                for(char ch = 'a';ch<='z';ch++){
                    currString[index] = ch;
                    // Check in word list
                    if(st.find(currString) != st.end()){
                        q.push({currString,currCount + 1});
                        st.erase(currString);
                    }
                }
                // bring back currString to original state
                currString[index] = originalChar;
            }
        }
        return 0;
    }
};