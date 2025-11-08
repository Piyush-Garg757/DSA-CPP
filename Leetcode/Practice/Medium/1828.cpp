/*Queries on Number of Points Inside a Circle
You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.
You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.
For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.
Return an array answer, where answer[j] is the answer to the jth query.

Example 1:
Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.*/
class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        vector<int> ans;
        int n = a.size(), m = b.size();
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                int dx = b[i][0] - a[j][0];
                int dy = b[i][1] - a[j][1];
                int r = b[i][2];
                if (dx * dx + dy * dy <= r * r)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n)