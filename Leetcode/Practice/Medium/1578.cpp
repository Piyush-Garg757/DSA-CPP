/*Minimum Time to Make Rope Colorful
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
Return the minimum time Bob needs to make the rope colorful.

Example 1:
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.*/
class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                // remove the one with smaller cost
                ans += min(cost[i], cost[i - 1]);
                // keep the higher cost for next comparison
                cost[i] = max(cost[i], cost[i - 1]);
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)