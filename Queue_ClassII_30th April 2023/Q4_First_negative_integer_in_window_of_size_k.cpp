#include <iostream>
#include <deque>
#include <vector>
using namespace std;
void solve(int arr[], int size, int k)
{
    vector<int> ans;
    // Create a deque
    deque<int> q;
    // Process first window of size = k
    for (int i = 0; i < k; i++)
    {
        // If negative number found, then simply insert index in queue
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }
    // Process the remaining windows
    for (int i = k; i < size; i++)
    {
        // First store answer of previous window
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int temp = arr[q.front()];
            ans.push_back(temp);
        }
        // Out of window element to be removed
        while (!q.empty() && (i - q.front()) >= k)
        {
            q.pop_front();
        }
        // Check current element whether negative or not. If negative then push index in queue
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }
    // For last window (as last window was not processed)
    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        int temp = arr[q.front()];
        ans.push_back(temp);
    }
    // Printing ans vector
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;
    int k = 3;
    solve(arr, size, k);
    return 0;
}