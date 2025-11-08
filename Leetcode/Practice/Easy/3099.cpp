/*Harshad Number

An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.*/

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int ans = 0, i = x;
        while (i != 0) {
            ans += i % 10;
            i /= 10;
        }
        if (x % ans == 0)
            return ans;
        return -1;
    }
};
// TC - O(log n)  SC - O(1)