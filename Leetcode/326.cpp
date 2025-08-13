// Power of three
/* 
Constraints:
-231 <= n <= 231 - 1*/

// Brute force
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        return (n % 3 == 0) && isPowerOfThree(n / 3);
    }
};
// TC - O(n)

// Optimised
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
// TC - O(1)
// ismein iss cheez ka fayda liya hai ki range di hui hai usmein 3^19 hi max to max aa sakti hai aur jo bhi number hoga agar vo 3 ki power hai to unka % 0 ana chahiye