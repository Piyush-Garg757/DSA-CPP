#include <bits/stdc++.h>
using namespace std;

void naive_string_match(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    bool found = false;
    for (int i = 0; i <= n - m; i++)
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
            found = true;
        }
    }
    if (!found)
    {
        cout << "Pattern not found" << endl;
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    naive_string_match(text, pattern);
    return 0;
}