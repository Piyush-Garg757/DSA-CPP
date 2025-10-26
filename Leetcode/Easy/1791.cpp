/*Find Center of Star Graph
Example 1:
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.*/
class Solution
{
public:
    int findCenter(vector<vector<int>> &a)
    {
        int ans = a[0][0];
        if (a[1][0] != ans && a[1][1] != ans)
            ans = a[0][1];
        return ans;
    }
};
// TC - O(1)  SC - O(1)