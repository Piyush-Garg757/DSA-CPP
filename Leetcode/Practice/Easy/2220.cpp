/*Minimum Bit Flips to Convert Number
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

Example 1:
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.*/
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        return __builtin_popcount(start ^ goal);
    }
};
// TC - O(1)  SC - O(1)

// __builtin_popcount(start ^ goal)  ye to stl hai 
// logically 1 count karne ho 1 to uske 2 methods hain
/*
1. while (x) {
        ans += x & 1;
        x >>= 1;
    }

2. int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}


2nd vala zyada efficient hai kyuki usmein jitne 1 hain  utni baar chalega na ki 32 baar  

its working - 🔍 Example

Let’s take n = 13
Binary form → 1101

Step 1:
n = 1101 (13)
n - 1 = 1100 (12)
n & (n - 1) = 1100
count = 1


Rightmost 1 cleared → now n = 12 (1100)

Step 2:
n = 1100
n - 1 = 1011
n & (n - 1) = 1000
count = 2

Step 3:
n = 1000
n - 1 = 0111
n & (n - 1) = 0000
count = 3


✅ Loop ends (n = 0).

👉 Total set bits = 3, which matches binary 1101.
*/