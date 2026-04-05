#include <bits/stdc++.h>
using namespace std;

void rabin_karp(string text, string pattern, int d = 256, int q = 101)
{
    int n = text.length();
    int m = pattern.length();
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t += q;
            }
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    rabin_karp(text, pattern);
    return 0;
}