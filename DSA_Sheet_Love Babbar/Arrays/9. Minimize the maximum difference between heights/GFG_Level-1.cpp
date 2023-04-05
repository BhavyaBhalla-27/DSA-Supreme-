// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1
class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // Step - 1 => Sort the array
        sort(arr, arr + n);
        // Intitial setup
        int mini = arr[0];
        int maxi = arr[n - 1];
        int diff = maxi - mini;
        // Iterate the array => i = 1 to n
        for (int i = 1; i < n; i++)
        {
            // Step - 2 => Update mini (Trying to find new minimum)
            mini = min(arr[0] + k, arr[i] - k);
            // Step - 3 => Update maxi (Trying to find new maximum)
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
            // Step - 4 => Update diff i.e. answer
            diff = min(diff, maxi - mini);
        }
        return diff;
    }
};