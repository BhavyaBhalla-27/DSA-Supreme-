// Array Index will start from 0 and not 1. The last index in the array is size - 1 where size is the number of elements in the array.
// Change the loop from (i = 1 to i<=5) to (i = 0 to i<5) 
#include<iostream>
using namespace std;
int main() {
   int arr[5] = {1, 2, 3, 4, 5};
   for(int i = 0; i < 5; i++) {
      cout << arr[i] << " ";
   }  
   return 0;
}