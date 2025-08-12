// to check whether a number is power of 2

// Brute Force
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        while ((n % 2) == 0)
            n /= 2;
        return (n == 1);
    }
};
// TC - O(Log(n))

// Optimised approach
class Solution {
public:
    bool isPowerOfTwo(int n) { 
        return (n > 0 && !(n & (n - 1))); }
};
// TC - O(1)

// concept - kisi bhi 2 ki power vale nmber mein bits ke representation mein khali 1 ata hai vo bhi ek jagah baaki sab 0 aate hain to hum check karenge ki kismein 1 hi 1 aa raha hai   agar aa raha hai to vo hai varna nahi
// ise check karne ke liye we did n & (n-1) agar 1 hi 1 hoga to iska answer 0 ayega