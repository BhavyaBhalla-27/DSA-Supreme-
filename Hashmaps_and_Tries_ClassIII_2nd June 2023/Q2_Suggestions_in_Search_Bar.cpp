#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char d){
            this->data = d;
            for(int i = 0;i<26;i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
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
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}
// Searching in tries
bool searchWord(TrieNode* root,string word){
    // base case -> All the characters finished, then simply return true or false whether it is terminal or not
    if(word.length() == 0)
        return root->isTerminal;
    // Fetch the index
    char ch = word[0];
    int index = ch - 'A';
    TrieNode* child;
    // If present then move to the next node
    if(root->children[index]!=NULL)
        child = root->children[index];
    // if not present simply return false
    else
        return false;
    // recursive call
    return searchWord(child,word.substr(1));
}
void storeSuggestion(TrieNode* curr,vector<string>&temp,string &prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }
    // Choice from a to z
    for(char ch='a';ch<='z';ch++){
        int index = ch - 'a';
        TrieNode* next = curr->children[index];
        if(next!=NULL){
            // children exists
            prefix.push_back(ch);
            storeSuggestion(next,temp,prefix);
            // Backtracking
            prefix.pop_back();
        }
    }
}
// n -> number of string
// m -> average length 
// O(nm^2)
vector<vector<string>>getSuggestions(TrieNode* root,string input){
    TrieNode* prev = root;
    vector<vector<string>>output;
    string prefix = "";
    for(int i = 0;i<input.length();i++){
        char lastCh = input[i];
        int index = lastCh - 'a';
        TrieNode* curr = prev->children[index];
        if(curr == NULL){
            break;
        }
        else{
            vector<string>temp;
            prefix.push_back(lastCh);
            storeSuggestion(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}
int main(){
    vector<string>v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";
    TrieNode* root = new TrieNode('-');
    for(int i = 0;i<v.size();i++){
        insertWord(root,v[i]);

    }

    vector<vector<string>>ans = getSuggestions(root,input);
    cout<<"Printing the answer"<<endl;
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}