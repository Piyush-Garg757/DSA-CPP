/*Strictly Palindromic Number
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.
Given an integer n, return true if n is strictly palindromic and false otherwise.
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.

Example 2:
Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.*/

/*For base (n−2):
Representation of n in base (n−2) is always "12"
"12" is not a palindrome.
So every number n ≥ 4 fails for base (n−2) itself!*/
// 1 2 3 hote hain just because koi base nahi hai check karne ko
class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        if (n >= 4)
            return false;
        return true;
    }
};
// TC - O(1)  SC - O(1)