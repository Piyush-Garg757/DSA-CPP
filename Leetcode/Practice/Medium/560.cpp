/*Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2*/

class Solution
{
public:
    int subarraySum(vector<int> &a, int k)
    {
        int j = 0, count = 0;
        unordered_map<int, int> mpp;
        mpp[j]++; // for initialising {0,1}
        for (int i = 0; i < a.size(); i++)
        {
            j += a[i];
            int check = j - k;
            if (mpp.find(check) != mpp.end())
            {
                count += mpp[check];
            }
            mpp[j]++;
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)