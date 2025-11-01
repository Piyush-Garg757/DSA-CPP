/*To Lower Case
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Example 1:
Input: s = "Hello"
Output: "hello"

Example 2:
Input: s = "here"
Output: "here"

Example 3:
Input: s = "LOVELY"
Output: "lovely"*/
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &i : s)
        {
            if (i >= 'A' && i <= 'Z')
            {
                i = i - 'A' + 'a';
            }
        }
        return s;
    }
};
// TC - O(n)  SC - O(1)

// Reason for using & :
/*In C++, when you use a range-based for loop like:

for (char i : s)
The loop variable i is a copy of the character from the string s in each iteration.

When you execute:
i = i - 'A' + 'a';
you successfully change the value of the local variable i from an uppercase letter to its lowercase equivalent, but this change is not written back to the original string s. The string s remains unmodified, and the function returns the original string.*/