/*Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4*/

// This is basically lower bound nikalna
class Solution
{
public:
    int searchInsert(vector<int> &a, int k)
    {
        int n = a.size();
        int high = n - 1, low = 0, ans = 0;
        if (k > a[n - 1])
            return n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
// TC - O(logn)  SC - O(1)