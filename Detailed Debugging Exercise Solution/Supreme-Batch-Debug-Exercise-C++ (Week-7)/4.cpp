// Mistake - 1 --> In the base case, == should be written instead of =
// Mistake - 2 --> 48 is the ASCII Value of 0 and hence this we have already seen that how to convert a character to integer

#include<iostream>
using namespace std;
int rec(char input[],int n){
    if(input[0] == '\0')
        return n;
    n = n * 10 + (input[0] - 48); 
    return rec(input + 1, n);
}

int stringToNumber(char input[]) {
    int n = 0;
    return rec(input, n);
}
int main(){
    char input[] = "1011";
    int ans = stringToNumber(input);
    cout<<ans;
    return 0;
}