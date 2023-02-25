// Convert the string to lowercase string
#include<iostream>
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
void convertToLowerCaseString(char name[]){
    int n = getLength(name);
    for(int i = 0;i<n;i++){
        if(name[i] >= 'A' && name[i] <='Z'){ // converting only capital letters
            name[i] = name[i] - 'A' + 'a';
        }
    }
}
int main(){
    char name[7] = "BHAVYA";
    convertToLowerCaseString(name);
    cout<<name;
    return 0;
}