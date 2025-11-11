/*Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.
Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).

Example 1:
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]*/
class Solution
{
public:
    bool isSelfDividing(int n)
    {
        int temp = n;
        while (temp > 0)
        {
            int d = temp % 10;
            if (d == 0 || n % d != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDividing(i))
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(n*k)  SC - O(1)
/*🧩 Why you might think it’s O(n log n)
Because you see a loop inside a loop:
Outer loop → iterates n times (right - left + 1 numbers).
Inner loop (while (temp > 0)) → divides by 10 each time ⇒ looks like log₁₀(n).
🔍 But here’s the real catch

log₁₀(n) = number of digits in n — that’s very small.
For integers ≤ 10⁹, the maximum number of digits = 10 — a constant.

👉 So even though the math says O(log n),
in practical computer terms it’s just a fixed constant (10 iterations max).*/