/*Number of Good Pairs
Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.*/

// Brute force
class Solution
{
public:
    int numIdenticalPairs(vector<int> &a)
    {
        int n = a.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                    count++;
            }
        }
        return count;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimal solution
class Solution
{
public:
    int numIdenticalPairs(vector<int> &a)
    {
        int n = a.size();
        unordered_map<int, int> mpp;
        int count = 0;
        for (int num : a)
        {
            count += mpp[num];
            mpp[num]++;
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)