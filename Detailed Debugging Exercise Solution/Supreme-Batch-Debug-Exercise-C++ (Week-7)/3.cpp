// We need to include cstring header file to use strlen function. Rest the output is fine here.
#include<iostream>
#include<cstring>
using namespace std;
void replacePi(char input[]) {
	if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'p' && input[1] == 'i'){
        int n = strlen(input);
        int i = 2;
        for(i = n+1; i >= 2; i--){
            input[i] = input[i-2];
        }
        input[n+2] = '\0';
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 1);
    }
    replacePi(input + 1);
}
int main(){
    char input[] = "xpix";
    replacePi(input);
    cout<<input;
    return 0;
}