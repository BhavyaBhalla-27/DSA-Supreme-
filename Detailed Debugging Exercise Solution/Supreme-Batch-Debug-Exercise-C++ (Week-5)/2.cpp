// While finding the maximum value, we need to compare with the minimum value and we took here INT_MIN
// Consdier the example of string ssaa, here if we use max<=count[str[i]] then a would be the answer but we were suppossed to find the first maximum occuring character and hence we need to use < symbol only.

#include <bits/stdc++.h>
using namespace std;
 
char maxOccurring(char* str)
{
    int count[256] = {0};
    int max = INT_MIN; // Modification done
    char answer;
 
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
        if (max < count[str[i]]) { // Modification done
            max = count[str[i]];
            answer= str[i];
        }
    }
    return answer;
}

int main()
{
    char str[] = "ssaa";
    cout << maxOccurring(str);
}