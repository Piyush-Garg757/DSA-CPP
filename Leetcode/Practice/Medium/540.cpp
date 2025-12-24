/*Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &a)
    {
        int n = a.size();
        if (n == 1)
            return a[0];
        if (a[0] != a[1])
            return a[0];
        if (a[n - 1] != a[n - 2])
            return a[n - 1];
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
                return a[mid];
            if (mid % 2 == 1 && a[mid] == a[mid - 1] ||
                mid % 2 == 0 && a[mid] == a[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
// TC - O(logn)  SC - O(1)