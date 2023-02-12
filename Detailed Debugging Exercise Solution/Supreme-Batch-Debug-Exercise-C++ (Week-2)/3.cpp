// In Line-9 we have mentioned int size = N, but there was no N declared and initialized before it, so I have initialized int N = 5; (Added Line - 8)
// In Line-13, in the for loop it should go till <=i rather than just <i. (Corrected line - 13)
// In Line-14, 2 stars were getting printed at a time but we just have to print a single star (Corrected line -14) 
#include <iostream>
using namespace std;
int main() {
  // size of the triangle
  int N = 5;
  int size = N;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print column
    for (int j = 0; j <=i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}