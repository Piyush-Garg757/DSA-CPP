/*Special Array I
An array is considered special if the parity of every pair of adjacent elements is different. In other words, one element in each pair must be even, and the other must be odd.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Example 1:
Input: nums = [1]
Output: true
Explanation:
There is only one element. So the answer is true.

Example 2:
Input: nums = [2,1,4]
Output: true
Explanation
There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true*/
class Solution
{
public:
    bool isArraySpecial(vector<int> &a)
    {
        for (int i = 0; i < a.size() - 1; i++)
        {
            if ((a[i] + a[i + 1]) % 2 == 0)
                return false;
        }
        return true;
    }
};
// TC - O(n)  SC - O(1)