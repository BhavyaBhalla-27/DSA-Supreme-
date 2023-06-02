#include<iostream>
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

int main(){
    TrieNode* root = new TrieNode('-');
    insertWord(root,"CODING");
    insertWord(root,"COD");
    insertWord(root,"CODIN");
    insertWord(root,"CODER");
    insertWord(root,"CODINGO");
    insertWord(root,"FLAMINGO");
    if(searchWord(root,"C")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}