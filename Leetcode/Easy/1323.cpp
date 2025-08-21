/*Maximum 69 Number
Example 1
Input: num = 9669
Output: 9969

Example 2:
Input: num = 9996
Output: 9999

Example 3:
Input: num = 9999
Output: 9999*/

class Solution {
public:
    int maximum69Number(int num) {
        int r_num = 0, a = 0;
        while (num) {
            r_num = r_num * 10 + num % 10;
            num /= 10;
        }
        num = 0;
        while (r_num) {
            int s = r_num % 10;
            if (s == 6 && a == 0) {
                a = 1;
                s = 9;
            }
            num = num * 10 + s;
            r_num /= 10;
        }
        return num;
    }
};

// Thoda better
#include<string>
class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(char &ch:s)
        {
            if(ch=='6') 
            {
                ch='9';
                break;
            }
        }
        return stoi(s);
    }
};
// stoi is string to integer function
// Time Complexity: O(n) where n is the number of digits in the number