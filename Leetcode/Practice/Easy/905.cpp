/*Sort Array By Parity
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]*/

// Brute force
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &a)
    {
        int n = a.size(), k = 0, j = n - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2)
                ans[j--] = a[i];
            else
                ans[k++] = a[i];
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Optimal code
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &a)
    {
        int l = 0, r = a.size() - 1;
        while (l < r)
        {
            if (a[l] % 2 > a[r] % 2)
                swap(a[l], a[r]);
            if (!(a[l] % 2))
                l++;
            if (a[r] % 2)
                r--;
        }
        return a;
    }
};
// TC - O(n)  SC - O(1)