/*Divisible and Non-divisible Sums Difference
Example 1:

Input: n = 10, m = 3
Output: 19
Explanation: In the given example:
- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
We return 37 - 18 = 19 as the answer.*/
class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        long long n1, n2;
        int a = n / m;
        n1 = m * ((a * (a + 1)) / 2);
        n2 = (n * (n + 1)) / 2;
        return n2 - 2 * n1;
    }
};
// TC - O(1)  SC - O(1)