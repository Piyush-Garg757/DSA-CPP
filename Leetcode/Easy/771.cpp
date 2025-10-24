/*Jewels and Stones
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0*/

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> mpp;
        int ans = 0;
        for (char ch : stones)
        {
            mpp[ch]++;
        }
        for (char ch : jewels)
        {
            if (mpp.count(ch))
                ans += mpp[ch];
        }
        return ans;
    }
};
// TC - O(m + n)  SC - O(n)

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> st(jewels.begin(), jewels.end());
        int ans = 0;
        for (char ch : stones)
        {
            if (st.count(ch))
                ans++;
        }
        return ans;
    }
};
// TC - O(m + n)  SC - O(n)

// TC and SC same in both but hash set one is bit faster 