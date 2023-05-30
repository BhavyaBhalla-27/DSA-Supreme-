#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // Creation
    unordered_map<string,int>m;
    // Insertion
    pair<string,int>p = make_pair("Scorpio",9);
    m.insert(p);
    pair<string,int>p2("A",10);
    m.insert(p2);
    m["fortuner"] = 6;
    // Accessing
    cout<<m.at("A")<<endl;
    cout<<m["fortuner"]<<endl;
    // Searching
    // Count function
    cout<<m.count("A")<<endl;
    cout<<m.count("B")<<endl;
    // Find function
    if(m.find("A")!=m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    // Iterating on the map
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}