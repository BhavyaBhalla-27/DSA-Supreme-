#include<iostream>
using namespace std;
void printSubSequence(string str,string output,int i){
    // Base Case
    if(i == str.length()){
        // print and then return
        cout<<output<<endl;
        return;
    }
    // Call for exclude (As it is)
    printSubSequence(str,output,i+1);
    // Call for include (Concatenate)
    output.push_back(str[i]);
    printSubSequence(str,output,i+1);
}
int main(){
    string str = "abc";
    string output = ""; // Initially empty
    int i = 0;
    printSubSequence(str,output,i);
    return 0;
}