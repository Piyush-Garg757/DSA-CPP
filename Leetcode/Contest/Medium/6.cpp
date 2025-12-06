/*Complete Prime Number
You are given an integer num.
A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.
Return true if num is a Complete Prime Number, otherwise return false.
Note:
A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
A prime number is a natural number greater than 1 with only two factors, 1 and itself.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.
 
Example 1:
Input: num = 23
Output: true
Explanation:
​​​​​​​Prefixes of num = 23 are 2 and 23, both are prime.
Suffixes of num = 23 are 3 and 23, both are prime.
All prefixes and suffixes are prime, so 23 is a Complete Prime Number and the answer is true.

Example 2:
Input: num = 39
Output: false
Explanation:
Prefixes of num = 39 are 3 and 39. 3 is prime, but 39 is not prime.
Suffixes of num = 39 are 9 and 39. Both 9 and 39 are not prime.
At least one prefix or suffix is not prime, so 39 is not a Complete Prime Number and the answer is false.

Example 3:
Input: num = 7
Output: true
Explanation:
7 is prime, so all its prefixes and suffixes are prime and the answer is true*/

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num)
    {
        string s = to_string(num);
        int n = s.length();
        for (int i = 1; i <= n; i++)
        {
            int prefix = stoi(s.substr(0, i));
            if (!isPrime(prefix))
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            int suffix = stoi(s.substr(i));
            if (!isPrime(suffix))
                return false;
        }
        return true;
    }
};
// TC - O(n*10^n/2)  SC - O(n)