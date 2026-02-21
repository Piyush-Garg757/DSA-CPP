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
        int ans;
        int one_c = 0, zero_c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                one_c++;
        }
        zero_c = n - one_c;
        if (one_c == 1 || zero_c = 0)
            ans = -1;
        else if (one_c == 0)
            ans = 0;
        else
            ans = zero_c;
        cout << ans << "\n";
        if (ans != -1 && ans != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    cout << i + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}