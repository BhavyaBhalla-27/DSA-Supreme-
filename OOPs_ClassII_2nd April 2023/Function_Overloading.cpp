#include<iostream>
using namespace std;
class Maths{
    // sum is existing in multiple forms
    
    public:
        int sum(int a,int b){
            return a+b;
        }
        int sum(int a,int b,int c){
            return a + b + c;
        }
        int sum(int a,float b){
            return a+b;
        }
};
int main(){
    Maths obj; 
    cout<<obj.sum(2,3)<<endl; // 1
    cout<<obj.sum(2,3,5)<<endl; // 2
    cout<<obj.sum(2,5.6f)<<endl; // 3
    return 0;
}