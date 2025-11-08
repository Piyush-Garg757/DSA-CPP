/*Richest Customer Wealth
A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Example 1:
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.*/
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size(), maxi = -1;
        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            for (int j = 0; j < m; j++)
            {
                ans += a[i][j];
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
// TC - O(n^2)  SC - O(1)