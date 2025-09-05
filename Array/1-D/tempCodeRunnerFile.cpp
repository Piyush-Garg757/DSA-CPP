#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, ans = 1;
    for (int i = 1; i < r; i++)
    {
        ans *= (r - i);
        ans /= i;
        cout << ans << " ";
    }
    return 0;
}
