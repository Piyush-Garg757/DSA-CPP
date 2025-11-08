/*Reverse Prefix of Word

Example 1:
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".*/
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int idx = word.find(ch);
        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};
// TC - O(1)  SC - O(1)