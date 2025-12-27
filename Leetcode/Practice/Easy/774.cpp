/*Find Smallest Letter Greater Than Target
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

Example 1:
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

Example 2:
Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

Example 3:
Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].*/

class Solution
{
public:
    char nextGreatestLetter(vector<char> &a, char k)
    {
        int l = 0, r = a.size() - 1;
        char ans = a[0];
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (a[m] > k)
            {
                ans = a[m];
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
// TC - O(logn)  SC - O(1)