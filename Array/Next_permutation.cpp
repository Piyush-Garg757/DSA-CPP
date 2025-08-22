// pehle print all permutations karte hain
#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << "\n";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        // Backtracking
        swap(s[l], s[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    permute(s, 0, s.size() - 1);
    return 0;
}
