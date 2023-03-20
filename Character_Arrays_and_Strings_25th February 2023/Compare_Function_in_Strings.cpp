#include<iostream>
using namespace std;
bool compareStrings(string a,string b){
    if(a.length() != b.length()){
        return false;
    }
    int n = a.length();
    for(int i = 0;i<n;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string a = "bhavya";
    string b = "bhavya";
    if(compareStrings(a,b)){
        cout<<"Equal";
    }
    else{
        cout<<"Not Equal";
    }
    return 0;
}