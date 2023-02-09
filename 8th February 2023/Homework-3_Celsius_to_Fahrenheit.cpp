#include<iostream>
using namespace std;
void convertToF(float temp){
    float F = (9*temp)/5 + 32; // Simple formulae for conversion
    cout<<"Temperature in fahrenheit is "<<F<<endl;
}
int main(){
    float temp = 37.3;
    convertToF(temp);
    return 0;
}