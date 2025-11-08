/*Sum Multiples
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.
Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.*/
class Solution
{
public:
    int sumDivisibleBy(int n, int x)
    {
        int k = n / x;
        return x * k * (k + 1) / 2;
    }
    int sumOfMultiples(int n)
    {
        return sumDivisibleBy(n, 3) + sumDivisibleBy(n, 5) +
               sumDivisibleBy(n, 7) - sumDivisibleBy(n, 15) -
               sumDivisibleBy(n, 21) - sumDivisibleBy(n, 35) +
               sumDivisibleBy(n, 105);
    }
};
// TC - O(1)  SC - O(1)