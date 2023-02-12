// First of all in Line-14, we have not declared j and we are using it so corrected it to int j = 1 (Corrected line-14)
// As we can see that we need to print the palindrome and hence we need to start from 2*i-1 rather than i-1(Corrected line-14)
// Also in the if condition it was if(1 || j<=k), In this j<=k is not checked at all as OR with 1 always give true and hence removed 1 || and changed the if condition to if(j<=k) --> Corrected line-15
#include <iostream>
using namespace std;
int main(){
    int k, n;
    cout << "Enter the number of rows : ";
    cin >> n;
    cout << " ";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1, k = 2*i - 1; j <= 2 * i - 1; j++, k--){
            if (j <= k)
                cout << j;
            else
                cout << k;
        }
        cout << endl;
        cout << " ";
    }
    return 0;
}