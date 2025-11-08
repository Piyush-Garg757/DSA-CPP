// Reverse Integer
/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).*/
/*Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21*/
class Solution {
public:
    int reverse_num(int x) {
        long long int i = 0;
        while (x) {
            i = i * 10 + x % 10;
            x /= 10;
        }
        if(INT_MIN<=i && i<=INT_MAX)
            return i;
        return 0;
    }
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        if (x < 0)
            return -(reverse_num(-x));
        return reverse_num(x);
    }
};
// TC - O(log(n))  SC - O(1)

/*if(INT_MIN<=i && i<=INT_MAX)
            return i;
        return 0;
ye vala check ismein iss line ki wajah se lagaya - If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.*/

/*if(x==INT_MIN) return 0;

aur ye vala isiliye kyuki INT_MIN hota hai -(2^31) aur INT_MAX hota hai 2^31 - 1 to INT_MIN k absolute lenge to vo range se bahar jaeyga  /