// There should be no return statement giving a value inside the void function. return; can be used in void however. So removed return str
// Also in strings, to mark the end we will use the inbuilt length function of the string i.e str.length()
#include<iostream>
#include<vector>
using namespace std;
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; i<s.length(); i++) {
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
    // Additional code for main function
    for(int i = 0;i<tmp.size();i++){
        cout<<tmp[i]<<" ";
    }
}
int main(){
    reverseWords("Hello World");
    return 0;

}