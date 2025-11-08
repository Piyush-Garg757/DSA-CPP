// Sprial matrix 2
// ismein matrix ko spiral way mein fill karna hai 1 se n^2 tak
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};
        vector<vector<int>> a(n, vector<int>(n));
        int s_row = 0, s_column = 0, e_row = n - 1, e_column = n - 1, count = 1;
        while (count <= n * n)
        {
            for (int j = s_column; j <= e_column && count <= n * n; j++)
                a[s_row][j] = count++;
            s_row++;
            for (int i = s_row; i <= e_row && count <= n * n; i++)
                a[i][e_column] = count++;
            e_column--;
            for (int j = e_column; j >= s_column && count <= n * n; j--)
                a[e_row][j] = count++;
            e_row--;
            for (int i = e_row; i >= s_row && count <= n * n; i--)
                a[i][s_column] = count++;
            s_column++;
        }
        return a;
    }
};
// TC - O(n*n)  SC - O(n*n)