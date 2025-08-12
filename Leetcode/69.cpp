/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
 
Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2.*/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
// TC - O(log(n))  SC - O(1)


// Newton's optimised approach
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long r = x;                  // initial guess (can be x/2+1 too)
        while (r > x / r) {               // safe: avoids r*r overflow
            r = (r + x / r) / 2;
        }
        return (int)r;                    // r is floor(sqrt(x))
    }
};
// TC - O(log(log(n)))  SC - O(1)