// Error - 1 Insted of i%n we need to mention n%i. (Corrected line 16)
// Error - 2 The code is giving wrong output for n < 2 and hence we need to mention the condition for the same. (Added code from line-9 to line-12)
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n<2){
        cout<<"Not Prime";
        return 0;
    }
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "Prime" << endl;
    }
    else
    {
        cout << "Not Prime" << endl;
    }
    return 0;
}