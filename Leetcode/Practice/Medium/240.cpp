/*Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0)
        {
            if (mat[row][col] == target)
            {
                return true;
            }
            else if (mat[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};
// TC - O(n+m)  SC - O(1)  