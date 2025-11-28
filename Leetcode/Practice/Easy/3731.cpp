/*Find Missing Elements
You are given an integer array nums consisting of unique integers.
Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
The smallest and largest integers of the original range are still present in nums.
Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

Example 1:
Input: nums = [1,4,2,5]
Output: [3]
Explanation:
The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

Example 2:
Input: nums = [7,8,6,9]
Output: []*/
class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = mn; i <= mx; i++)
        {
            if (!st.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)