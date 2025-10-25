/*2824. Count Pairs Whose Sum is Less than Targets[j] < target.

Example 1:
Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.*/
// Brute to O(n^2)
class Solution
{
public:
    int countPairs(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int i = 0, j = n - 1, count = 0;
        while (i < j)
        {
            if (a[i] + a[j] < k)
            {
                count += (j - i);
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
    }
};
// TC - O(nlogn)  SC - O(1)