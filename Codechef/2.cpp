/*Buying Tickets
Chef wants to buy tickets to a sports game for K people (including himself).
The sports game has N total seats, numbered 1 to N. The i-th seat costs Ai rupees.
However, several seats have already been bought, because Chef was late to the task. You are given a binary string S, where Si = 1 if the i-th seat has already been bought and Si = 0 otherwise.
Among the remaining seats, what is the minimum cost Chef has to pay to buy K seats?
It is not required that the seats be consecutive or any other property. It may be impossible to buy K seats, in which case print -1.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line contains 2 integers - N and K, the number of seats and the number of people.
The second line contains N integers - A1, …, AN.
The third line contains a binary string S.

Output Format
For each test case, output on a new line the minimum cost Chef has to pay to buy K tickets, or -1 if impossible.
Constraints

1 ≤ T ≤ 100
1 ≤ K ≤ N ≤ 100
1 ≤ Ai ≤ 100
Si ∈ {0,1}

Input
3
4 3
1 1 1 1
0000
4 3
4 2 6 8
1100
4 3
4 2 6 8
0100

Output
3
-1
18

Explanation:
Test Case 1 : Chef can buy seats 1, 2 and 3 for a total cost of 1+1+1 = 3.
Test Case 2 : There are only 2 seats left, and Chef wants to buy 3.*/

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
        string s;
        cin >> s;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({a[i],
                         s[i] - '0'});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto &p : v)
        {
            if (p.second != 1 && k > 0)
            {
                ans += p.first;
                k--;
            }
        }

        if (k > 0)
            ans = -1;
        cout << ans << "\n";
    }
}
// TC - O(nlogn)  SC - O(n)

// ise aise bhi kar sakte the ki jahan jahan 0 hai unka ek lag vector banaye unhein sort karke fir kare    tc sc same hi ata fir bhi 