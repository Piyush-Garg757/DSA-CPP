/*Counting Bits
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101*/

// STL approach
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Normal approach
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Bit manipulation
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)
// ho ismein bhi same hi raha hai >>1 matlab /2 aur &1 matlab %2