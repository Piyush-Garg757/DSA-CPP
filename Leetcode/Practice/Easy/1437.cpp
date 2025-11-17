/*Check If All 1's Are at Least Length K Places Away
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

Example 1:
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.*/
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int j1 = -1, j2 = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                j2 = j1;
                j1 = i;
            }
            if (j1 != -1 && j2 != -1 && j1 - j2 - 1 < k)
                return false;
        }
        return true;
    }
};
// TC - O(n)  SC - O(n)