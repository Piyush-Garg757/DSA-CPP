/*Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.

Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.*/
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> st(allowed.begin(), allowed.end());
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int a = 0;
            for (char j : words[i])
            {
                if (!st.count(j))
                {
                    a = 1;
                    break;
                }
            }
            if (!a)
                ans++;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)