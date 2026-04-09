/*K Median
You have an array A of N integers, and an integer K. You must delete exactly K elements from the array.
After deleting K elements, you wonder what are the possible median values of the remaining array. Print all of the possible median values.
The median of an array B of length M is the ⌈M/2⌉ smallest element. For example the median of [2,4,3,1] is 2 and the median of [1,2,2] is also 2.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line contains 2 integers N and K.
The second line contains N integers - A1, A2, …, AN.

Output Format
For each test case, output on a new line all the possible medians after deleting K elements, in sorted order.

Constraints
1 ≤ T ≤ 100
1 ≤ K < N ≤ 100
1 ≤ Ai ≤ 10^9

Sample Input
5
4 1
4 2 1 3
4 2
4 2 1 3
4 3
78 19 100 25
6 4
1 3 7 10 15 21
6 4
5 5 5 5 5 5

Sample Output
2 3
2 3
19 25 78 100
1 3 7 10 15
5

Explanation:
Test Case 1: We are allowed only 1 deletion.
We can delete the element [1] to get [2,3,4] which has a median of 3.
We can delete the element [3] to get [1,2,4] which has a median of 2.
It can be shown that no other medians are possible.*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int m = n - k;
        int p = (m - 1) / 2;
        set<int> st;
        for (int i = p; i <= p + k; i++)
            st.insert(a[i]);
        for (auto x : st)
            cout << x << " ";
        cout << "\n";
    }
}
// TC - O(nlogn)  SC - O(n)