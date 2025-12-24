/*Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.*/

class Solution
{
public:
    int ispossible(vector<int> &a, int k, int mid)
    {
        int sum = 0, y = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (sum + a[i] <= mid)
            {
                sum += a[i];
            }
            else
            {
                y++;
                sum = 0;
                i--;
            }
        }
        return y <= k;
    }
    int splitArray(vector<int> &a, int k)
    {
        int maxi = INT_MIN, sum = 0, ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            maxi = max(maxi, a[i]);
            sum += a[i];
        }
        int low = maxi, high = sum;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (ispossible(a, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(1)