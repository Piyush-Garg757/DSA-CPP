/*Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

Example 1:
Input: nums = [3,4,5,2]
Output: 12
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.*/
class Solution
{
public:
    int maxProduct(vector<int> &a)
    {
        int n = a.size(), max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else if (a[i] > max2)
                max2 = a[i];
        }
        return (max1 - 1) * (max2 - 1);
    }
};
// TC - O(n)  SC - O(1)