/*1317. Convert Integer to the Sum of Two No-Zero Integers

Example 1:
Input: n = 2
Output: [1,1]

Example 2:
Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.*/
class Solution {
public:
    bool check(int n) {
        while (n) {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        int a = 1;
        while (check(a) || check(n - a)) {
            a++;
        }
        ans.push_back(a);
        ans.push_back(n - a);
        return ans;
    }
};