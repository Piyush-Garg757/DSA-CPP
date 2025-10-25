/*Goal Parser Interpretation
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.

Example 1:
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal"*/
class Solution
{
public:
    string interpret(string s)
    {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'G')
                ans.push_back('G');
            else if (s[i] == '(')
            {
                if (s[i + 1] == 'a')
                {
                    ans.push_back('a');
                    ans.push_back('l');
                    i = i + 3;
                }
                else
                {
                    ans.push_back('o');
                    i++;
                }
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)