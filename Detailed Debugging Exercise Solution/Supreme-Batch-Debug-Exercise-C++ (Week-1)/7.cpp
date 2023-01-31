// Error - 1 -> The first inner for loop of spaces will run from j = 1 to n-i because ith row has n - i spaces. For example 1st row has n-1 spaces, 2nd row has n-2 spaces and so on (Corrected line-10)
// Error - 2 -> The left pyramid will be running till 2*i - 1 as we can see that the 1st row runs till 2x1 - 1 = 2-1 = 1, 2nd row runs till 2x2 - 1 = 4 - 1 = 3 and so on (Corrected line - 14)
// Error - 3 -> First important observation is that the right pyramid will start from even number so 2 will be multiplied and it will start from 2*(i-1). Like 1st row will have no right pyramid as 2x(1-1) = 0. 2nd row 2x(2-1) = 2 (start from 2), 3rd row 2x(3-1) = 2x(2) = 4. (Corrected line - 17)
#include<iostream>
using namespace std;
int main() {
  int n;
  std::cin>>n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i ; j++) {
    // First we need to print the spaces and the spaces is equal to n - rowNumber (i)
      printf("  ");
    }
    for (int j = i; j <2*i; j++) {
      printf("%d ", j);
    }
    int ele = 2*(i-1);
    for (int j = 1; j <= i - 1; j++) {
      printf("%d ", ele--);
    }
    printf("\n");
  }
  return 0;
}