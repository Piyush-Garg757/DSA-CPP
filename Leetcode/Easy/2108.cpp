/*Find First Palindromic String in the Array
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.*/
class Solution
{
public:
    bool is(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (string s : words)
        {
            if (is(s))
                return s;
        }
        return "";
    }
};
// TC - O(n^2)  SC - O(1)