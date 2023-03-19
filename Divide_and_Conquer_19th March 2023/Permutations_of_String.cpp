#include<iostream>
using namespace std;
void printPermutations(string &str,int i){
    // Base Case
    if(i >= str.length()){
        cout<<str<<" ";
        return;
    }
    // Swapping 
    for(int j = i; j<str.length();j++){
        // Swap
        swap(str[i],str[j]);
        // Recursive call
        printPermutations(str,i+1);
        // Backtracking Line
        swap(str[i],str[j]);
    }
}
int main(){
    string s = "abc";
    int i = 0;
    printPermutations(s,i);
    return 0;
}