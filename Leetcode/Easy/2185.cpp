/*Counting Words With a Given Prefix
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".*/

// Without using stl
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        int n = pref.size();

        for (const string &s : words)
        {
            if (s.size() < n)
                continue; // can't be a prefix
            bool match = true;

            for (int i = 0; i < n; i++)
            {
                if (s[i] != pref[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                count++;
        }

        return count;
    }
};
// TC - O(n^2)  SC - O(1)

// Using STL (My first approach)
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int n = pref.length(), count = 0;
        for (string s : words)
        {
            if (s.substr(0, n) == pref)
                count++;
        }
        return count;
    }
};
// TC - O(n^2)  SC - O(n)  as we are creating substrings

// Most optimal using stl
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (const string &s : words)
        {
            if (s.size() >= pref.size() && s.rfind(pref, 0) == 0)
                count++;
        }
        return count;
    }
};
// TC - O(n^2)  SC - O(1)

/*s.rfind(pref, 0) → checks if pref occurs starting at index 0 (i.e., as a prefix).
It returns 0 if it starts with pref, else string::npos.*/