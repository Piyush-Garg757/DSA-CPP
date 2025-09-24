// set matrix zero
class Solution
{
public:
    void setZeroes(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    a[i][j] = 0;
                }
            }
        }
    }
};
// TC - O(n^2)  SC - O(n) + O(m)
// optimised way jismein SC O(1)