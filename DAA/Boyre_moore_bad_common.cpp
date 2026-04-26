#include <bits/stdc++.h>
using namespace std;

vector<int> badChar(string pat) {
    vector<int> bad(256, -1);
    for(int i = 0; i < pat.size(); i++)
        bad[pat[i]] = i;
    return bad;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.size(), m = pattern.size();
    vector<int> bad = badChar(pattern);

    int s = 0;
    bool found = false;

    while(s <= n - m) {
        int j = m - 1;

        while(j >= 0 && pattern[j] == text[s + j])
            j--;

        if(j < 0) {
            cout << "Pattern found at index " << s << endl;
            found = true;
            s += (s + m < n) ? m - bad[text[s + m]] : 1;
        } else {
            s += max(1, j - bad[text[s + j]]);
        }
    }

    if(!found) cout << "Pattern not found";
}