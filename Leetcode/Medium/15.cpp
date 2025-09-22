// 3sum
/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && a[i] == a[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = a[i] + a[l] + a[r];
                if (sum == 0)
                {
                    ans.push_back({a[i], a[l], a[r]});
                    while (l < r && a[l] == a[l + 1])
                        l++;
                    while (l < r && a[r] == a[r - 1])
                        r--;
                    l++;
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(1)