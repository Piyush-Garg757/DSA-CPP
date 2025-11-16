/*Maximize Expression of Three Elements
You are given an integer array nums.
Choose three elements a, b, and c from nums at distinct indices such that the value of the expression a + b - c is maximized.
Return an integer denoting the maximum possible value of this expression.

Example 1:
Input: nums = [1,4,2,5]
Output: 8
Explanation:
We can choose a = 4, b = 5, and c = 1. The expression value is 4 + 5 - 1 = 8, which is the maximum possible.©leetcode*/
class Solution
{
public:
    int maximizeExpressionOfThree(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        return a[n - 1] + a[n - 2] - a[0];
    }
};
// TC - O(nlogn)  SC - O(1)