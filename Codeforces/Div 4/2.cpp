/*D. The 67th OEIS Problem

Construct a sequence a containing n integers such that gcd(ai, ai+1) is distinct for all 1 ≤ i ≤ n−1. It is guaranteed that at least one sequence exists.
OEIS refers to the Online Encyclopedia of Integer Sequences.
gcd(x, y) refers to the greatest common divisor of integers x and y.

Input:
The first line contains an integer t (1 ≤ t ≤ 100) — the number of test cases.
Each of the next t lines contains one integer n (2 ≤ n ≤ 10000) — the desired length of the sequence.
It is guaranteed that the sum of n over all test cases does not exceed 10000.

Output:
For each test case, output a sequence a of n space-separated integers (1 ≤ ai ≤ 10^18) such that gcd(ai, ai+1) are all distinct.

Example:

Input:
2
3
5

Output:
1 6 2
134 67 69 207 414

Explanation:
In the first test case:
Sequence → [1, 6, 2]
gcd(1, 6) = 1
gcd(6, 2) = 2
Both are distinct.

In the second test case:
Sequence → [134, 67, 69, 207, 414]
Each adjacent gcd value is different.*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            int x = 2 * i - 1;
            int y = 2 * i + 1;
            int ans = x * y;
            cout << ans;
            if (i < n)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n)  SC - O(1)