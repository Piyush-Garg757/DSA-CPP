// Power of 4

// Brute force
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 == 0)
            return isPowerOfFour(n / 4);
        return false;
    }
};
// TC - O(log n) SC - O(log n)
// ismein sc bhi ologn hua kyuki
/*Example
If n = 64:
64 → 16 → 4 → 1 → (stop)
That’s 3 recursive calls → stack depth = 3 → space O(log n).*/

// ismein sc o(logn) hai isiliye iterative approachh is se better hai.kyuki ussmein tc same hai aur sc bhi o(1) hai.


// Better approach
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

// Optimal approach
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
// TC - O(1) SC - O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};
// TC - O(1) SC - O(1)

// iska explanation ye hai ki 4 ki power ke liye binary representation mein sirf 1 bit set hota hai aur wo bit odd position par hota hai.
/*to hum 0x55555555 (binary: 01010101010101010101010101010101) ka use karke ye check kar sakte hain ki set bit odd position par hai ya nahi.
hex ->binary
0x5 = 0101 (binary)
0x55 = 01010101 (binary)
0101 0101 0101 0101 0101 0101 0101 0101
   5    5    5    5    5    5    5    5
so isi tarah se hum check kar sakte hain ki 4 ki power hai ya nahi.
*/