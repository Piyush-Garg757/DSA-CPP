/*Balloon Smash Party
There are N friends at a party playing a game called Balloon Smash. Each friend i has an annoyance factor Ai.
If the i-th friend is hit by Ai balloons, they immediately leave the party.
The game proceeds according to the following rules:
The friends take turns sequentially from 1 to N.
If the current friend has already left the party, the turn moves to the next friend.
If there is no next friend available, the game ends.
When it is friend i's turn and they are still present in the party:
Friend i hits every other friend currently present in the party with exactly one balloon.
After doing so, friend i leaves the party.
Then, for any remaining friend j who has been hit by Aj balloons so far, this friend will immediately leave the party.
Your task is to determine how many balloons hit each friend by the time the party ends.
---

Input Format
The first line contains a single integer T, denoting the number of test cases.
Each test case consists of two lines:
The first line contains a single integer N, the number of friends.
The second line contains N space-separated integers
A1, A2, …, AN
where Ai is the annoyance factor of the i-th friend.
---

Output Format
For each test case, output a single line containing N integers.
The i-th integer should denote the total number of balloons that hit friend i by the end of the party.
---

Constraints

1 ≤ T ≤ 10^4
2 ≤ N ≤ 2 × 10^5
1 ≤ Ai ≤ N
The sum of N over all test cases does not exceed 2 × 10^5.

---

Sample 1

Input
2
3
2 2 2
4
3 1 3 3

Output
0 1 2
0 1 1 2
---
Explanation
Test case 1:
N = 3
A = [2,2,2]
Initially all friends {1,2,3} are in the party and everyone has received 0 balloons.
Turn 1 (Friend 1 is present):
Friend 1 hits every other present friend.
Friends 2 and 3 each receive +1 balloon.
Balloons received = [0,1,1]
No one has reached their annoyance limit yet (limit is 2 for all).
Friend 1 leaves the party.
Remaining friends = {2,3}
Turn 2 (Friend 2 is present):
Friend 2 hits every other present friend.
Friend 3 receives +1 balloon.
Balloons received = [0,1,2]
Friend 2 leaves after finishing the turn.
Friend 3 has now received 2 balloons which equals A3 = 2, so Friend 3 immediately leaves.
Remaining friends = {}
No friends remain, so the game ends.
Final balloons received by each friend = [0,1,2].
---
Test case 2:
Turn 1:
Friend 1 hits everyone else with a balloon and leaves.
Since A2 = 1, friend 2 also leaves immediately.
Turn 2:
Friend 2 is already gone, so we move to friend 3.
Friend 3 hits the only remaining person (friend 4) and then leaves.
Turn 3:
Friend 4 remains but there is nobody else left to hit.
The game ends.
Final balloons received = [0,1,1,2].
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector < int > a(n), ans(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int hits = 0;
        for (int i = 0; i < n; i++)
        {
            ans[i] = min(a[i], hits);
            if (ans[i] < a[i])
                hits++;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
// TC - O(n)  SC - O(1)