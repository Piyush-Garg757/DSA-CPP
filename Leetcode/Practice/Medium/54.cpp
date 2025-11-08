// Sprial matrix
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &a)
    {
        int n = a.size();
        if (n == 0)
            return {};
        int m = a[0].size();
        vector<int> ans;
        int s_row = 0, s_column = 0, e_row = n - 1, e_column = m - 1,
            count = n * m;
        while (count > 0)
        {
            for (int j = s_column; j <= e_column && count > 0; j++)
            {
                ans.push_back(a[s_row][j]);
                count--;
            }
            s_row++;
            for (int i = s_row; i <= e_row && count > 0; i++)
            {
                ans.push_back(a[i][e_column]);
                count--;
            }
            e_column--;
            for (int j = e_column; j >= s_column && count > 0; j--)
            {
                ans.push_back(a[e_row][j]);
                count--;
            }
            e_row--;
            for (int i = e_row; i >= s_row && count > 0; i--)
            {
                ans.push_back(a[i][s_column]);
                count--;
            }
            s_column++;
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n^2)