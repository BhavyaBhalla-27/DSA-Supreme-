#include<iostream>
using namespace std;

void reverseString(char input[],int n,int start){
    for(int i=start,j=n-1+start;i<j;i++,j--){
        swap(input[i],input[j]); // Used swap function
    }
}

void reverseEachWord(char input[]) {
    int start=0,count=1,i=0;
    while(input[i]!=0){
        i++;
        count++;
        if((input[i]==' ' || input[i] == '\0')){ // Check for string termination is added
            reverseString(input,count-1,start);
            start = i+1;
            count = 0;
        }
    }
}
int main(){
    char input[] = "Hello World";
    int n = 11;
    reverseEachWord(input);
    for(int i = 0;i<n;i++){
        cout<<input[i];
    }
    return 0;
}