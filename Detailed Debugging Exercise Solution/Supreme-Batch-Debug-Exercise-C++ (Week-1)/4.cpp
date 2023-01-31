// Error - 1 We are not incrementing the value of j and hence we will stuck up in an infinite loop. Change ++i to ++j (Corrected line - 9)
// Error - 2 Inside the inner for loop we need to remove \n character as it will always jump to next line and this is not a square pattern. insted of \n we add space. (Corrected line-10)
#include<iostream>
using namespace std;
int main() {
		int n;
        cin>>n;
        for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout<<"* ";
        }
        cout<<endl;
    }
}