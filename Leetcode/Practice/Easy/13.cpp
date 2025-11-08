/*Roman to Integer
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.*/


class Solution
{
public:
    int value(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return -1;
    }
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int n1 = value(s[i]);
            if (i + 1 < s.length())
            {
                int n2 = value(s[i + 1]);
                if (n1 < n2)
                {
                    ans += (n2 - n1);
                    i++;
                    continue;
                }
            }
            ans += n1;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

