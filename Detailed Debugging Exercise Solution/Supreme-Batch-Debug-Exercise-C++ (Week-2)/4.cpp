// In Line-12, there were 2 spaces printing at a time but we just one space so I correct it to cout<<" " instead of cout<<"  "; (Corrected Line - 12)
// In Line - 15, the formulae for finding stars in each row was incorrected and the corrected formulae would be 2*size - 2*i - 1 instead of 2*size - 1 (Corrected line - 15)
#include <iostream>
using namespace std;
int main() {
  // size of the pyramid
  int size; 
  cin>>size;
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // print stars
    for (int k = 0; k < 2 * size - 2*i - 1; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}