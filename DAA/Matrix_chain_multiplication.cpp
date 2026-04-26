#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum number of multiplications: " << dp[0][n - 1];
}