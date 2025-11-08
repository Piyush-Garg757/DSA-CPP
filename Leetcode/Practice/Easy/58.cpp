// Length of last word
/*Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4

Example 3:
Input: s = "luffy is still joyboy"
Output: 6*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, count = 0;
        while (s[i] == ' ' && i >= 0)
            i--;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};
// TC - O(n)  SC - O(1)