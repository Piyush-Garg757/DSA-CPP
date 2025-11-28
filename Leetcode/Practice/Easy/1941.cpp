/*Check if All Characters Have Equal Number of Occurrences
Given a string s, return true if s is a good string, or false otherwise.
A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.*/

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> mpp;
        for (char i : s)
        {
            mpp[i]++;
        }
        int a = 0, ans1 = -1;
        for (auto i : mpp)
        {
            if (a == 0)
            {
                a = 1;
                ans1 = i.second;
            }
            else
            {
                if (i.second != ans1)
                    return false;
            }
        }
        return true;
    }
};
// TC - O(n)  SC - O(1)