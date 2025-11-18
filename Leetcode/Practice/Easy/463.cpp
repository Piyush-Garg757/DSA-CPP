/*Island Perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4

Example 3:
Input: grid = [[1,0]]
Output: 4*/

// My first approach
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    ans += 4;
                    if (i != n - 1 && a[i + 1][j] == 1)
                        ans--;
                    if (i != 0 && a[i - 1][j] == 1)
                        ans--;
                    if (j != m - 1 && a[i][j + 1] == 1)
                        ans--;
                    if (j != 0 && a[i][j - 1] == 1)
                        ans--;
                }
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(1)

// Most optimal answer
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    ans += 4;
                    if (i + 1 < n && a[i + 1][j] == 1)
                        ans -= 2;
                    if (j + 1 < m && a[i][j + 1] == 1)
                        ans -= 2;
                }
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(1)