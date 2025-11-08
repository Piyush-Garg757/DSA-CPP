/*Subtract the Product and Sum of Digits of an Integer
Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
*/
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0, prod = 1;
        while (n)
        {
            int x = n % 10;
            prod *= x;
            sum += x;
            n /= 10;
        }
        return prod - sum;
    }
};
// TC - O(logn)  SC - O(1)