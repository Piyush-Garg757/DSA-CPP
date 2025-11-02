/*
Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.*/
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &a)
    {
        int n = a.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i][i];
            if (i != n - i - 1)
                sum += a[i][n - i - 1];
        }
        return sum;
    }
};
// TC - O(n)  SC - O(1)