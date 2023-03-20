#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str;
    cin>>str; // taking input in string
    getline(cin,str); // to read spaces
    // inbuilt functions use
    string st = "Bhavya";
    cout<<st.length()<<endl;
    cout<<st.empty()<<endl;
    st.push_back('A');
    st.pop_back();
    cout<<st.substr(0,6)<<endl;
    cout<<st.compare("Bhavya")<<endl;
    string sentence = "Hello all";
    cout<<sentence.find("Hello")<<endl;
    sentence.replace(0,5,"hi");
    cout<<sentence<<endl;
    sentence.erase(0,5);
    cout<<sentence<<endl;
    return 0;
}