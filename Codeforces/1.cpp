/*
C. Dice Roll Sequence
time limit per test2 seconds
memory limit per test256 megabytes
Consider the following cube D where numbers x and 7−x lie on opposite sides:
A sequence b of integers from 1 to 6 is called a dice roll sequence if it satisfies the following condition:
All pairs of adjacent elements lie on adjacent∗ sides of the cube.
For example, [1,4,2] is a dice roll sequence, while [3,4,6,3] is not because 3 and 4 are not on adjacent sides of the dice. Additionally, [2,2,4] is not a dice roll sequence because 2 and 2 are on the same (not adjacent) side of the dice.
Given a sequence a of n integers from 1 to 6, you can perform the following operation any number of times (possibly zero).
Select an index 1≤i≤n and an integer 1≤x≤6. Then, change the value of ai to x.
Please determine the minimum number of operations required to make a a dice roll sequence.
∗Two sides of the cube S and T are called adjacent if they share exactly one edge of the cube. Do note that this condition implies S≠T as well.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤3⋅105).
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤6).
It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case, output the minimum number of operations required to make a a dice roll sequence.
Example
Input
3
3
1 4 2
4
3 4 6 3
10
6 1 4 3 1 3 2 5 4 4

Output
0
1
4

Note
For the first test case, the sequence a is [1,4,2]. As this is already a dice roll sequence, the answer is 0.
For the second test case, the sequence a is [3,4,6,3].
Changing exactly one element, you can get [3,5,6,3], which is a dice roll sequence.
For the third test case, the sequence a is [6,1,4,3,1,3,2,5,4,4].
Changing exactly 4 elements, you can get [5,1,4,2,1,3,2,1,5,4], which is a dice roll sequence.
*/

#include <bits/stdc++.h>
using namespace std;
bool conflict(int a, int b)
{
    if (a == b)
        return true;
    if (a == 7 - b)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ops = 0;
        for (int i = 0; i + 2 < n; i++)
        {
            int first = a[i];
            int mid = a[i + 1];
            int last = a[i + 2];
            bool c1 = conflict(mid, first);
            if (c1)
            {
                for (int x = 1; x <= 6; x++)
                {
                    if (x == first)
                        continue;
                    if (x == last)
                        continue;
                    if (x == 7 - first)
                        continue;
                    if (x == 7 - last)
                        continue;
                    a[i + 1] = x;
                    break;
                }
                ops++;
            }
        }
        if (n >= 2)
        {
            int second_last = a[n - 2];
            int last = a[n - 1];
            if (conflict(second_last, last))
            {
                for (int x = 1; x <= 6; x++)
                {
                    if (x == second_last)
                        continue;
                    if (x == 7 - second_last)
                        continue;
                    a[n - 1] = x;
                    break;
                }
                ops++;
            }
        }
        cout << ops << '\n';
    }
    return 0;
}
// TC - O(n)  SC - O(1)