/*Flipping an Image
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.
For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
For example, inverting [0,1,1] results in [1,0,0].*/
class Solution
{
public:
    void reverse_row(vector<int> &a)
    {
        int n = a.size(), i = 0, j = n - 1;
        while (i < j)
        {
            swap(a[i++], a[j--]);
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse_row(a[i]);
        }
        return a;
    }
};
// TC - O(n^2)  SC - O(1)

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= (m - 1) / 2; j++)
            {
                if (a[i][j] == a[i][m - 1 - j])
                {
                    a[i][j] = a[i][m - 1 - j] = 1 - a[i][j];
                }
            }
        }
        return a;
    }
};
// TC - O(n^2)  SC - O(1) but one pass so it is most optimised version
