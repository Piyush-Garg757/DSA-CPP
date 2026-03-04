/*Min And Operations
You are given a set S containing exactly N + 1 numbers:
S = {0, 1, 2, …, N} (each value appearing exactly once).
It is guaranteed that N is even.
Initially, your score is 0.
You must perform operations as long as S has at least two elements remaining in it.
In each operation:
Choose and remove two distinct elements X and Y from the set.
Add max(X, Y) to your score.
Reinsert X & Y back into the set if and only if it does not exist already.
Here, & denotes the bitwise AND operation.
For example, suppose
S = {0, 2, 3, 4, 5}.
If you choose X = 2 and Y = 4, your score will increase by max(2,4) = 4.
Then, you must delete 2 and 4 from the set; and because 2 & 4 = 0 is already present in the set, you must not insert it again.
This turns the set into
{0,3,5}.
If you instead choose X = 3 and Y = 5, your score will increase by 5.
Then, you delete 3 and 5 from the set; and since 3 & 5 = 1 is not present in the set, you must insert it; obtaining
{0,1,2,4}.
Find the minimum possible final score you can obtain after performing operations till S only has a single remaining element.
---

Input Format
The first line contains an integer T denoting the number of test cases.
Each test case consists of a single integer N.
---

Output Format
For each test case, print a single integer — the minimum possible final score.
---

Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 5 × 10³
N is even.
The sum of N over all test cases does not exceed 5 × 10³.

---

Sample 1

Input
3
2
4
50

Output
2
6
650

---
Explanation
Test case 1:
Initial set:
{0,1,2}
score = 0
Operation 1: choose X = 1, Y = 2
Remove 1 and 2 ⇒ set becomes {0}
Add max(1,2) = 2 ⇒ score = 2
Since (1 & 2) = 0 already exists in set, nothing gets inserted.
Since we cannot perform any more operations, minimum possible final score is 2.
*/

// By observation through test cases

#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = n / 2;
        cout << k * (k + 1) << endl;
    }
}
// TC - O(1)  SC - O(1)