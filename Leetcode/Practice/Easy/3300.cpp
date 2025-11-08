/*Minimum Element After Replacement With Digit Sum
You are given an integer array nums.
You replace each element in nums with the sum of its digits.
Return the minimum element in nums after all replacements.

Example 1:
Input: nums = [10,12,13,14]
Output: 1
Explanation:
nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.*/
class Solution
{
public:
    int minElement(vector<int> &a)
    {
        int mini = INT_MAX;
        for (int num : a)
        {
            int sum = 0, temp = num;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
                if (sum > mini)
                    break;
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};
// TC - O(n * log₁₀(max(a[i])))  SC - O(1)