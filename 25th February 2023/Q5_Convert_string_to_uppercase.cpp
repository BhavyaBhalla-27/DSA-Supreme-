#include<iostream>
#include<string.h>
using namespace std;
void convertStringToUpper(char name[]){
    int n = strlen(name);
    for(int i = 0;i<n;i++){
        if(name[i]>='a' && name[i]<='z')
            name[i] = name[i] - 'a' + 'A'; // formulae developed
    }
}
int main(){
    char name[100] = "bhavya";
    convertStringToUpper(name);
    cout<<name<<endl;
    return 0;
}