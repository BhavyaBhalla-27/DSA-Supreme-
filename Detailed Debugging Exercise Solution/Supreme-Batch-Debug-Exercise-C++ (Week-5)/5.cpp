// This code will put the characters from character array to the string and hence LAKSHAY will be prined when string j is printed.

#include <iostream>  
using namespace std;  
int main() {  
    char char_array[] = {'L','A','K','S','H','A','Y'};  
    int array_size = sizeof(char_array);  
    string j = "";  
    int i;  
    for(i = 0; i<array_size; i++) {    
        j = j + char_array[i];  
    }  
    cout << j <<endl;  
}