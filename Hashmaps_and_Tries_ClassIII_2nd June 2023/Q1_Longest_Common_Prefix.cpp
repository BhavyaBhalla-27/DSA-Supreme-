// https://leetcode.com/problems/longest-common-prefix/

// Brute force
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        // loop for first string
        for(int i = 0;i<strs[0].length();i++){
            char ch = strs[0][i];
            bool match = true;
            // compare the character fetched with all the strings
            for(int j = 1;j<strs.size();j++){
                // compare
                if(strs[j].size() < i || ch!=strs[j][i]){
                    match = false;
                    // If not match, hence no need to check further strings
                    break;
                }
            }
            // match false
            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

// Using tries
class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                this->isTerminal = false;
                childCount = 0;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->childCount++;
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}
void findLCP(string first,string &ans,TrieNode* root){
    // Here I can do mistake
    if(root->isTerminal)
        return;
    for(int i = 0;i<first.length();i++){
        char ch = first[i];
        if(root->childCount == 1){
            ans.push_back(ch);
            // move forward
            int index = ch - 'a';
            root = root->children[index];
        }
        else{
            break;
        }
        // If root is terminal
        if(root->isTerminal){
            break;
        }
    }
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        // Insert the characters in trie
        for(int i = 0;i<strs.size();i++){
            insertWord(root,strs[i]);
        }
        string ans = "";
        // So that we can move forward by using the characters
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;
    }
};

