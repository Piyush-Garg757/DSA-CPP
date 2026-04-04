/*C. The 67th Permutation Problem

You are given an integer n. You must construct a permutation of length 3n such that, if you partition the permutation into n contiguous blocks with 3 elements, the sum of the medians of these blocks is maximised.
More formally, you must construct a permutation p of length 3n such that:
sum over i = 0 to n-1 of median(p[3i+1], p[3i+2], p[3i+3]) is maximised.
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not (2 appears twice), and [1,3,4] is also not valid for n=3.
The median of an array of 3 elements is the second element after sorting in non-decreasing order.

Input:
The first line contains an integer t (1 ≤ t ≤ 10000) — the number of test cases.
Each test case contains a single integer n (1 ≤ n ≤ 100000).
It is guaranteed that the sum of 3n over all test cases does not exceed 300000.

Output:
For each test case, output a permutation p of length 3n such that the sum of medians of the contiguous blocks is maximised. If there are multiple answers, print any.

Example:

Input:
3
2
1
3

Output:
1 3 4 2 5 6
3 1 2
5 2 4 8 3 9 7 1 6

Explanation:
In the first test case:
Blocks → [1,3,4] and [2,5,6]
Medians → 3 + 5 = 8 (maximum possible)

In the second test case:
Only one block → median = 2*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> res;
        int l = 1, r = 3 * n;
        for (int i = 0; i < n; i++)
        {
            res.push_back(l++);
            res.push_back(r - 1);
            res.push_back(r);
            r -= 2;
        }
        for (int x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// TC - O(n)  SC - O(1)