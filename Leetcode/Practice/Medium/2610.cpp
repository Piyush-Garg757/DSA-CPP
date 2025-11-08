/*Convert an Array Into a 2D Array With Conditions
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.
Note that the 2D array can have a different number of elements on each row.

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.*/
// Brute force
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &a)
    {
        unordered_map<int, int> mpp;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            mpp[a[i]]++;
        }
        int maxi = 0;
        for (auto i : mpp)
        {
            maxi = max(maxi, i.second);
        }
        vector<vector<int>> v;
        for (int i = 0; i < maxi; i++)
        {
            vector<int> ans;
            for (auto j : mpp)
            {
                if (j.second >= i + 1)
                    ans.push_back(j.first);
            }
            v.push_back(ans);
        }
        return v;
    }
};
// TC - O(n^2)  SC - O(n)

// Thoda optimise
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &a)
    {
        unordered_map<int, int> mpp;
        int n = a.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            mpp[a[i]]++;
            maxi = max(maxi, mpp[a[i]]);
        }
        vector<vector<int>> v;
        for (int i = 0; i < maxi; i++)
        {
            vector<int> ans;
            for (auto &j : mpp)
            {
                if (j.second >= i + 1)
                    ans.push_back(j.first);
            }
            v.push_back(ans);
        }
        return v;
    }
};
// TC - O(n^2)  SC - O(n)

// Optimised solution
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &a)
    {
        unordered_map<int, int> mpp;
        vector<vector<int>> ans;
        for (int x : a)
        {
            int count = mpp[x]++;
            if (ans.size() == count)
                ans.push_back({});
            ans[count].push_back(x);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)