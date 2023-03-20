#include<iostream>
using namespace std;
bool checkKey(string str,int i,int n,int key){
    // Base case -> Traverse whole string
    if(i == n)
        return false;
    // Solve 1 case rest recursion will see
    if(str[i] == key)
        return true;
    // move ahead in the traversal
    return checkKey(str,i+1,n,key);
}
int main(){
    string str = "lovebabbar";
    int n = str.length();
    char key = 's';
    int i = 0;
    bool ans = checkKey(str,i,n,key);
    cout<<ans<<endl;
    return 0;
}