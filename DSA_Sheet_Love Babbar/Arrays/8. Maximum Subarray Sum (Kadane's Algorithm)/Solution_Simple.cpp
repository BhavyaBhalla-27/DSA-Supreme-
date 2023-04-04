#include <iostream>
#include <vector>
using namespace std;
int maxSubArraySum(vector<int> &nums)
{
    // Initial steps
    int sum = 0;
    int maxi = nums[0];
    // Traverse the array
    for (int i = 0; i < nums.size(); i++)
    {
        // Step - 1 =>
        sum = sum + nums[i];
        // Step - 2 =>
        maxi = max(sum, maxi);
        // Step - 3 =>
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArraySum(nums);
    cout << "Maximum subarray sum = " << ans;
    return 0;
}