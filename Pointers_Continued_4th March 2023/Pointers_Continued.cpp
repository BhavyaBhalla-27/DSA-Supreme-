#include<iostream>
using namespace std;
int main(){
    int arr[4] = {12,13,14,15};
    cout<<arr<<endl; // Base address of array
    cout<<arr[0]<<endl; // 12
    cout<<&arr<<endl; // Base address of array
    cout<<&arr[0]<<endl; // Base address of array
    int *ptr = arr;
    cout<<ptr<<endl; // Base Address of array 
    cout<<&ptr<<endl;; // Address of pointer block
    cout<<*(arr) + 1<<endl; // 12 + 1 = 13 will be printed
    cout<<*arr+1<<endl; // 12 + 1 = 13 will be printed
    cout<<*(arr+1)<<endl; // arr[1] will be printed that is 13
    cout<<2[arr]<<endl; // arr[2] will be printed i.e. 14
    // arr = arr + 2; // Will not work as we can't change the value present in symbol table
    int *p = arr;
    p = p + 2;
    cout<<&arr[2]<<endl;
    cout<<p<<endl; // Same address of arr[2]

    // Pointer vs Array
    int brr[10];
    cout<<sizeof(brr)<<endl; // 10*4 = 40 bytes
    int *p1 = brr;
    cout<<sizeof(p)<<endl; // 8 bytes
    // arr = arr + 1 -> cant be done
    // p1 = p1 + 1 --> can be done

    // Character array
    char ch[10] = "Babbar";
    char *c = ch;
    cout<<ch<<endl; // Babbar
    cout<<&ch<<endl; // Base address
    cout<<ch[0]<<endl; // B
    cout<<&c<<endl; // Address of pointer block
    cout<<*c<<endl; // B
    cout<<c<<endl; // Babbar
    // Special case
    char character = 'v';
    char *cptr = &character;
    cout<<cptr<<endl;
    // Bad practice below
    char *ctr = "Bhavya";
    cout<<ctr<<endl; // Warning will come
    return 0;
}