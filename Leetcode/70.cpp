// Climbing The Stairs
/*ou are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps*/

// Brute Force
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// TC - O(2^n)  SC - O(n) (due to recursion stack)

// Optimised
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2; 
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
// TC - O(n)  SC - O(1)

// Optimised
#include <cmath>
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2.0;
        double psi = (1 - sqrt5) / 2.0;

        double fib_n = (pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5;
        return (int)round(fib_n); // round to nearest int due to floating-point error
    }
};
// TC - O(1)  SC - O(1)
/* the O(1) way uses Binet’s Formula for Fibonacci numbers.

The climbing stairs problem is just:

ways(n) = F(n+1)
Binet's formula -> F(n)= (phi^n - psi^n)/root(5)
phi=(1+root(5))/2  (golden ratio)
psi=(1-root(5))/2*/
// Works instantly, but for very large n (like > 90), floating-point precision can make results wrong