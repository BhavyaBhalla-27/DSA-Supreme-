#include<iostream>
using namespace std;
int global = 6;
int main(){
    int a; // declared variable 
    int b = 5; // intialization of variable b
    b = 10;
    // int b = 6 -> This won't work and will give us error (redefined)
    if(true){
        int b = 7;
        cout<<b<<endl; // scope inside if statement
    }
    cout<<b<<endl; // scope inside main()
    cout<<global; // printing global variable
    return 0;
}