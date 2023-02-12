// In Line - 12, j was starting from 0 and it was printing one star more than the desired output and hence I changed it to start from j = 1 to print one star less (Corrected Line - 12)
// In Line - 31, i++ was done and hence we were going in an infinite loop as i = size is a positive number and condition was i>0 and we were doing i++, so the condition was always true and hence I changed it i--.
#include <iostream>
using namespace std;
int main() {
  // heart star pattern
  int size;
  cin>>size;

  for (int i = size / 2; i < size; i += 2) {
    // print first spaces
    for (int j = 1; j < size - i; j += 2) { // started from j = 1
      cout << " ";
    }
    // print first stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    // print second spaces
    for (int j = 1; j < size - i + 1; j++) {
      cout << " ";
    }
    // print second stars
    for (int j = 1; j < i + 1; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  // lower part
  // inverted pyramid
  for (int i = size; i > 0; i--) {
    for (int j = 0; j < size - i; j++) {
      cout << " ";
    }
    for (int j = 1; j < i * 2; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}