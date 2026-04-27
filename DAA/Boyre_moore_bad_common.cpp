// #include <bits/stdc++.h>
// using namespace std;

// vector<int> badChar(string pat) {
//     vector<int> bad(256, -1);
//     for(int i = 0; i < pat.size(); i++)
//         bad[pat[i]] = i;
//     return bad;
// }

// int main() {
//     string text, pattern;

//     cout << "Enter text: ";
//     cin >> text;
//     cout << "Enter pattern: ";
//     cin >> pattern;

//     int n = text.size(), m = pattern.size();
//     vector<int> bad = badChar(pattern);

//     int s = 0;
//     bool found = false;

//     while(s <= n - m) {
//         int j = m - 1;

//         while(j >= 0 && pattern[j] == text[s + j])
//             j--;

//         if(j < 0) {
//             cout << "Pattern found at index " << s << endl;
//             found = true;
//             s += (s + m < n) ? m - bad[text[s + m]] : 1;
//         } else {
//             s += max(1, j - bad[text[s + j]]);
//         }
//     }

//     if(!found) cout << "Pattern not found";
// }

#include <bits/stdc++.h>
using namespace std;

// 🔥 Bad Match Shift Table
vector<int> buildShiftTable(string pat)
{
    int m = pat.size();
    vector<int> shift(256, m); // default = m

    for (int i = 0; i < m; i++)
    {
        shift[pat[i]] = m - i - 1; // 🔥 tera formula
    }

    return shift;
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.size(), m = pattern.size();
    vector<int> shift = buildShiftTable(pattern);

    int s = 0;
    bool found = false;

    while (s <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            cout << "Pattern found at index " << s << endl;
            found = true;
            s += shift[text[s + m]]; // next char based shift
        }
        else
        {
            s += max(shift[text[s + j]], 1); // 🔥 direct table lookup
        }
    }

    if (!found)
        cout << "Pattern not found";
}