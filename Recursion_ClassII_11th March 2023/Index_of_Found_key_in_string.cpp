#include<iostream>
using namespace std;
int checkKey(string str,int i,int n,int key){
    // Base case -> Traverse whole string
    if(i == n)
        return -1;
    // Solve 1 case rest recursion will see
    if(str[i] == key)
        return i;
    // move ahead in the traversal
    return checkKey(str,i+1,n,key);
}
int main(){
    string str = "lovebabbar";
    int n = str.length();
    char key = 's';
    int i = 0;
    int ans = checkKey(str,i,n,key);
    cout<<ans<<endl;
    return 0;
}