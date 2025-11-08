/*Check if the Sentence Is Pangram
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:
Input: sentence = "leetcode"
Output: false*/
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        if (sentence.length() < 26)
            return false;
        unordered_set<char> st(sentence.begin(), sentence.end());
        char i = 'a';
        while (i <= 'z')
        {
            if (st.count(i++) == 0)
                return false;
        }
        return true;
    }
};
// TC - O(n)  SC - O(1)

// Since yahan kaha hai only english alphabets honge string mein na ki dusre charecters top humn ek aur cheez kar sakte hain
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        if (sentence.size() < 26)
            return false;
        unordered_set<char> st(sentence.begin(), sentence.end());
        return st.size() == 26;
    }
};
// TC - O(n)  SC - O(1)