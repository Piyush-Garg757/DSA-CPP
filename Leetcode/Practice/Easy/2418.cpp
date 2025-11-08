/*Sort the People
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
For each index i, names[i] and heights[i] denote the name and height of the ith person.
Return names sorted in descending order by the people's heights.

Example 1:
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.*/

// My first approach
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        unordered_map<int, string> mpp;
        for (int i = 0; i < names.size(); i++)
        {
            mpp[heights[i]] = names[i];
        }
        sort(heights.rbegin(), heights.rend()); // rbegin rend se descending order mein sort hota hai
        for (int i = 0; i < names.size(); i++)
        {
            names[i] = mpp[heights[i]];
        }
        return names;
    }
};
// TC - O(nlogn)  SC - O(n)

// Most optimal
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> v;
        for (int i = 0; i < names.size(); i++)
            v.push_back({heights[i], names[i]});

        sort(v.rbegin(), v.rend()); // sorts directly by height descending

        vector<string> ans;
        for (auto &p : v)
            ans.push_back(p.second);

        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)