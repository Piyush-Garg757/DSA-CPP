/*Maximum Odd Binary Number
You are given a binary string s that contains at least one '1'.
You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.

Example 1:
Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".

Example 2:
Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".*/
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int c1 = 0, n = s.length();
        for (char i : s)
            if (i == '1')
                c1++;
        s[n - 1] = '1';
        c1--;
        for (int i = 0; i < n - 1; i++)
        {
            if (c1)
            {
                s[i] = '1';
                c1--;
            }
            else
                s[i] = '0';
        }
        return s;
    }
};
// TC - O(n)  SC - O(1)