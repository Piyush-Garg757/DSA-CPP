/*Running Sum of 1d Array

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].*/
class Solution
{
public:
    vector<int> runningSum(vector<int> &a)
    {
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i] + a[i - 1];
        }
        return a;
    }
};
// TC - O(n)  SC - O(1)