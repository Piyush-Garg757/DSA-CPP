/*Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.*/

// My first approach
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long long odd = 0, even = 0, p = 0;
        while (odd < n && even < n)
        {
            if (p % 2)
                odd += pow(2, p);
            else
                even += pow(2, p);
            p++;
        }
        if (odd == n || even == n)
            return true;
        return false;
    }
};
// TC - O(logn)  SC - O(1)

// Most optimal sol
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
// TC - O(1)  SC - O(1)

// Explanation  

/*Step 1: Alternating bits ka pattern samajh
Alternating numbers:
5  = 101
10 = 1010
21 = 10101
Notice:
har adjacent bit different hota hai
Step 2: n >> 1 kya karega?
Right shift:
n       = 10101
n >> 1  = 01010
Bits ek position right shift ho gaye.
Step 3: XOR ka magic
XOR rule:
same bits → 0
different bits → 1
Ab XOR karte hain:
   10101
^  01010
---------
   11111
👉 Agar bits alternating hain → result ALL 1s aata hai.
Try non-alternating:
n = 111
n>>1 = 011
111 ^ 011 = 100
All 1s nahi aaya.
Step 4: All 1s check ka trick
Binary property:
Numbers like:
1      = 1
3      = 11
7      = 111
15     = 1111
In sab ke liye:
x & (x+1) == 0
Example:
x = 111
x+1 = 1000
111 & 1000 = 0*/