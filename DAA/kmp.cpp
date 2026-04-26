#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0, i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    int n = text.size(), m = pattern.size();
    bool found = false;

    while(i < n) {
        if(text[i] == pattern[j]) {
            i++; j++;
        }

        if(j == m) {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }

    if(!found) cout << "Pattern not found";
}