#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(char first,char second){
    return first > second; // returns true if first is greater than second else it will return false
}
bool cmp1(int a,int b){
    return a>b; // Place a first if a > b else place b first 
}
int main(){
    string s = "bhavya"; 
    sort(s.begin(),s.end(),cmp); // custom comparator will be the last parameter
    cout<<s; // Prints string in reverse order
    cout<<endl; 
    vector<int>v{3,1,4,5,2}; // Simply creating vector
    sort(v.begin(),v.end(),cmp1); // Sort on the basis of comparator and that too in decreasing order
    for(auto i:v){
        cout<<i<<" "; // decreasing order elements will be printed
    }
    return 0;
}