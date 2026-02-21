/*A. String Rotation Game
Define a block in a string as a contiguous substring of characters of the same type that cannot be extended either to the left or the right. For example, in the string aabcccdaa, there are five blocks:
aa (1st to 2nd characters)
b (3rd character)
ccc (4th to 6th characters)
d (7th character)
aa (8th to 9th characters)
You are playing a game where you are given a string s of length n. You can cyclically rotate the string however you want. Your score is then calculated as the number of blocks in the final string. Please find the maximum score possible.
Formally, choose an index 1 ≤ i ≤ n, and replace the string s1s2…sn with the string si+1 si+2 … sn s1 s2 … si. For example, the string abcde can be rotated to string deabc by choosing i = 3.

Input:
Each test contains multiple test cases.
The first line contains the number of test cases t (1 ≤ t ≤ 500).
The description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100).
The second line of each test case contains the string s of length n.
Strings s consist of lowercase Latin characters only.

Output:
For each test case, output a single integer denoting the maximum score you can achieve.
Example:

Input:
4
4
abcd
4
abbc
4
abba
6
abbccc

Output:
4
4
3
4

Note:
In the first test case, score of the original string abcd is 4. It can be shown that a score greater than 4 cannot be achieved.
In the second test case, cyclically rotating the string by 2 positions will give us string bcab. Score of this string is 4. It can be shown that a score greater than 4 cannot be achieved.*/

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
        string s;
        cin >> s;
        int i = 0, count = 0, a = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && s[j] == s[i])
            {
                a = 1;
                j++;
            }
            count++;
            i = j;
        }
        if (a == 1 && s[0] != s[n - 1])
            count++;
        cout << count << "\n";
    }
    return 0;
}
// TC - O(n)  SC - O(1)