#include<iostream>
#include<string.h>
using namespace std;
int getLength(char name[]){
    int len = 0;
    int i = 0;
    while(name[i] != '\0'){
        len++;
        i++;
    }
    return len;
}
int main(){
    char name[100];
    cin>>name;
    int length = getLength(name);
    cout<<"Length of string = "<<length<<endl;
    cout<<strlen(name);
    return 0;
}