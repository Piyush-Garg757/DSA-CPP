/*Find Words Containing Characterte that the returned array may be in any order.

Example 1:
Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

Example 2:
Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.*/
// Brute force
class Solution
{
public:
    int check(string s, char x)
    {
        for (char i : s)
        {
            if (i == x)
                return 1;
        }
        return 0;
    }
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (check(words[i], x))
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n)

// Optimal solution
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != string::npos)
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n)
// still tc is same but it is using built in stl so it is bit faster
/*What it means:
words[i] → current word (a std::string)
.find(x) → searches for the first occurrence of character x inside that word
It returns the index (position) where x is found — or something special if it’s not found.

The special value — string::npos
string::npos is a constant that means “not found”.
Its value is usually -1 (represented as the largest size_t value internally).*/