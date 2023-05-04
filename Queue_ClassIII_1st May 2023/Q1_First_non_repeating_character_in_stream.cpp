#include<iostream>
#include<queue>
using namespace std;
void solve(string& s){
    // Count array -> 26 size as there are 26 alphabets
    int count[26] = {0};
    queue<char>q;
    string ans = "";
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        // Increment frequency
        count[ch-'a']++;
        // Push in queue
        q.push(ch);
        while(!q.empty()){
            // Repeating character found
            if(count[q.front() - 'a'] > 1){
                q.pop();
            }
            // Frequency = 1 and can't be less than 1 as it already is in queue and it has come from the string
            else{
                ans.push_back(q.front());
                break;
            }
        }
        // Non-repeating character not found
        if(q.empty()){
            ans.push_back('#');
        }
    }
    cout<<ans;
}
int main(){
    string s = "aabc";
    solve(s);
    return 0;
}