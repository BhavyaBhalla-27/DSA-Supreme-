#include<iostream>
using namespace std;
float areaCircle(float r){
    return 3.14*r*r;
}
int main(){
    float r = 2.5;
    cout<<"Area of circle is "<<areaCircle(r)<<endl;
    return 0;
}