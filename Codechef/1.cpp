/*
Odd Operations

You are given an integer N. You can perform the following two types of operations on N:

Digit Subtraction: Choose any digit present in the current decimal representation of N and subtract it from N.
Digit Reordering: Rearrange (permute) the digits of N to form a new integer (Leading zeros are not allowed). For example, 1067 can be rearranged to 7106 but not to 10670. Also, 90 cannot be rearranged to 9.

Determine the minimum number of operations required to make N an odd number.
If it is impossible to make N odd using the given operations, print -1.

Input        Output
5
246          3
10           1
8            -1
343          0
42           2

Explanation

For the first test case, N = 246.
One optimal sequence of operations is:
Subtract digit 6:
246 − 6 = 240
Subtract digit 2:
240 − 2 = 238
Subtract digit 3:
238 − 3 = 235, which is odd
Hence, the minimum number of operations required is 3.

For the second test case, N = 10.
Subtract digit 1 from 10 to get 9, which is odd.
Hence, the answer is 1.

For the third test case, N = 8.
It is impossible to make N odd and the answer is -1.

For the fourth test case, N = 343.
The number is already odd, so no operations are required.
Hence, the answer is 0.

For the fifth test case, N = 42.
One optimal sequence is:
Subtract digit 4:
42 − 4 = 38
Reorder 38 to 83
Hence, the answer is 2.*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, a = 0, maxi = INT_MIN;
        cin >> n;
        if (n % 2 != 0)
            cout << "0\n";
        else
        {
            string s = to_string(n);
            if (s.length() == 1)
                cout << "-1\n";
            else
            {
                for (char i : s)
                {
                    if ((i - '0') % 2 != 0)
                    {
                        cout << "1\n";
                        a = 1;
                        break;
                    }
                    maxi = max(maxi, i - '0');
                }
                if (!a)
                {
                    if (maxi == (s[s.length() - 1] - '0'))
                        cout << "3\n";
                    else
                        cout << "2\n";
                }
            }
        }
    }
}
// TC - O(log(n)/log(10))  SC - O(n)