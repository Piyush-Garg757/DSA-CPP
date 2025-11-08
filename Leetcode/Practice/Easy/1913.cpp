/*Maximum Product Difference Between Two Pairs
The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.
Return the maximum such product difference.

Example 1:
Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.*/

// Brute force
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};
// TC - O(nlogn)  SC - O(1)

// Optimal sol
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int max1 = 0, max2 = 0, min1 = INT_MAX, min2 = INT_MAX;
        for (int x : nums)
        {
            if (x > max1)
            {
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
                max2 = x;

            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
                min2 = x;
        }
        return (max1 * max2) - (min1 * min2);
    }
};
// TC - O(n)  SC - O(1)