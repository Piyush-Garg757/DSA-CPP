/*Count the Digits That Divide a Number
Example 1:

Input: num = 7
Output: 1
Explanation: 7 divides itself, hence the answer is 1.
Example 2:

Input: num = 121
Output: 2
Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.*/
class Solution
{
public:
    int countDigits(int n)
    {
        int a = n, count = 0;
        while (a)
        {
            if (n % (a % 10) == 0)
                count++;
            a /= 10;
        }
        return count;
    }
};
// TC - O(logn)  SC - O(1)