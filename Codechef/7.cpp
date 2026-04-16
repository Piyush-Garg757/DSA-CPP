/*Non-Negative Sum
You have an array A of N integers - [A1, A2, …, AN].
Find the largest subsequence of this array with a non-negative sum. If no such subsequence exists, print 0 instead.
B is said to be a subsequence of A if B can be formed by deleting several (possibly 0) elements from A without changing the order of the remaining elements. For example, [2], [1,3] and [1,2,3] are subsequences of [1,2,3] but [1,1] and [2,1] are not.

Input Format

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer N.
The second line contains N integers - A1, A2, …, AN.

Output Format
For each test case, output on a new line the maximum size of a subsequence with a non-negative sum.

Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 100
−100 ≤ Ai ≤ 100

Sample 1:

Input
4
5
2 4 -2 -5 -3
3
1 3 5
2
-1 -2
2
1 -1

Output
4
3
0
2

Explanation:

Test Case 1: The subsequence [2, 4, −2, −3] has length 4 and a sum of 1 which is non-negative.*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        int sum = 0, count = 0;
        for (int x : a)
        {
            if (sum + x >= 0)
            {
                sum += x;
                count++;
            }
        }
        cout << count << endl;
    }
}
// TC - O(nlogn)  SC - O(1)