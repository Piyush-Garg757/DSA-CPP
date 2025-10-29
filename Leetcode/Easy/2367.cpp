/*Number of Arithmetic Triplets
You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

Example 1:
Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. */
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        for (int x : nums)
        {
            if (s.count(x + diff) && s.count(x + 2 * diff))
                count++;
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)  
// Brute force to vahi 0(n^3) hoga 