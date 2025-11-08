/*Smallest Number With All Set Bits
You are given a positive number n.
Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

Example 1:
Input: n = 5
Output: 7
Explanation:
The binary representation of 7 is "111".
Example 2:
Input: n = 10
Output: 15
Explanation:
The binary representation of 15 is "1111".*/
class Solution
{
public:
    int smallestNumber(int n)
    {
        return pow(2, int(log(n) / log(2)) + 1) - 1;
    }
};
// TC - O(1)  SC - O(1)