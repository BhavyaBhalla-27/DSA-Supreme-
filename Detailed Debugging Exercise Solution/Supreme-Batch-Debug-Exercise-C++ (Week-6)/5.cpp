// The question is to find the third element means 3rd position i.e. 2nd index element
// *(ptr + i) = arr[i];
// Hence update *(ptr + 3) to *(ptr + 2) to find the 2nd index element
#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    cout << "The value of the third element in arr is " << *(ptr + 2) << endl;
    return 0;
}