// Largest 3-Same-Digit Number in String
/*You are given a string num representing a large integer. An integer is good if it meets the following conditions:
It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Example 1:
Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

Example 3:
Input: num = "42352338"
Output: ""*/

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxStr = "";
        int n = num.length();
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string current = num.substr(i, 3);
                if (current > maxStr) {
                    maxStr = current;
                }
            }
        }
        return maxStr;
    }
};
// TC - O(n)