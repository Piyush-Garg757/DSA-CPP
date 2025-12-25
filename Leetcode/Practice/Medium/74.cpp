/*Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &a, int k)
    {
        int n = a.size(), m = a[0].size();
        int low = 0, high = n * m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midi = mid / m, midj = mid % m;
            int check = a[midi][midj];
            if (check == k)
                return true;
            else if (check < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
// TC - O(log(n*m))  SC - O(1)