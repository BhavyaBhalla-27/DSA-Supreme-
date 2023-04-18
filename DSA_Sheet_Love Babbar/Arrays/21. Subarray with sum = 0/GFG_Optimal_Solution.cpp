// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

bool subArrayExists(int arr[], int n)
{
    // Initial settings
    unordered_map<int, int> m;
    int sum = 0;
    // Traverse the array and find the prefix sum
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        // 2 condition we need to check
        if ((sum == 0) || m[sum] == 1)
        {
            return true;
        }
        // Update map
        else
        {
            m[sum] = 1;
        }
    }
    return false;
}