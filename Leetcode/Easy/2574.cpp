/*2574. Left and Right Sum Differences

Example 1:
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].*/
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &a)
    {
        int n = a.size();
        vector<int> left(n), right(n);
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] + a[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + a[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = abs(left[i] - right[i]);
        }
        return a;
    }
};
// TC - O(n)  SC - O(n)

// Optimised approach
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n);
        int totalSum = 0;
        for (int x : a)
            totalSum += x;
        int leftSum = 0;
        for (int i = 0; i < n; i++)
        {
            int rightSum = totalSum - leftSum - a[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += a[i];
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)