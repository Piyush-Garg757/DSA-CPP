/*Smallest Index With Digit Sum Equal to Index
You are given an integer array nums.
Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
If no such index exists, return -1.

Example 1:
Input: nums = [1,3,2]
Output: 2
Explanation:
For nums[] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
Example 2:
Input: nums = [1,10,11]
Output: 1
Explanation:
For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.*/
class Solution
{
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumOfDigits(nums[i]) == i)
                return i;
        }
        return -1;
    }
};
// TC - O(nlogn)  SC - O(1)