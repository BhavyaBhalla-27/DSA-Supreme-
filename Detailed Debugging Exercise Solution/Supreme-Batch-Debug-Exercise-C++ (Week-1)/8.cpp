// Error - 1  k will be declared outside the inner for loop as when k is incremented it is again set to 0 as the control moves up. (Added line - 10 and Removed line - 13)
// Error - 2 k++ will be inside else if because when spaces are getting printed then k is also getting updated and hence we end up going in else and hence start printing spaces again 
// Error - 3 k == 2*i - 1 changed to k == 2*i. Reason is mentioned below
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        // Last row will have 2*n - 1 stars i.e. 2*n - 1 columns which is represented by j.
        for (int j = 0; j < 2*n - 1; ++j)
        {
            
            if (j < n - i - 1)
            {
                cout <<" ";
            }
            else if (k < 2 * i + 1)
            {
                // i == n-1 means last row and hence all the stars will be printed
                // k == 0 for the first row star gets printed
                // k == 2*i for last column the stars will be printed
                if (k == 0 || k == 2 * i  || i == n - 1)
                {
                    cout <<"*";
                }
                else
                {
                    cout <<" ";
                }
                k++;
            }
            else
            {
                cout <<" ";
            }
            
        }
        cout << endl;
    }
}