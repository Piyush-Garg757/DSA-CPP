/*Check If Two String Arrays are Equivalent
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.*/

// Brute  force
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1, s2;
        for (auto i : word1)
        {
            s1 += i;
        }
        for (auto i : word2)
        {
            s2 += i;
        }
        return s1 == s2;
    }
};
// TC - O(n)  SC - O(n)

// Optimised
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int i = 0, j = 0;
        int p1 = 0, p2 = 0;
        while (i < word1.size() && j < word2.size())
        {
            if (word1[i][p1] != word2[j][p2])
                return false;
            p1++;
            p2++;
            if (p1 == word1[i].size())
            {
                p1 = 0;
                i++;
            }
            if (p2 == word2[j].size())
            {
                p2 = 0;
                j++;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};
// TC - O(n)  SC - O(1)