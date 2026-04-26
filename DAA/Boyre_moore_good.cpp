#include <bits/stdc++.h>
using namespace std;

vector<int> suffix(string pat) {
    int m = pat.size();
    vector<int> suff(m);
    suff[m-1] = m;
    int g = m-1, f = 0;

    for(int i = m-2; i >= 0; i--) {
        if(i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if(i < g) g = i;
            f = i;
            while(g >= 0 && pat[g] == pat[g + m - 1 - f]) g--;
            suff[i] = f - g;
        }
    }
    return suff;
}

vector<int> goodSuffix(string pat) {
    int m = pat.size();
    vector<int> gs(m, m);
    vector<int> suff = suffix(pat);

    int j = 0;
    for(int i = m-1; i >= 0; i--) {
        if(suff[i] == i + 1) {
            for(; j < m-1-i; j++)
                if(gs[j] == m) gs[j] = m-1-i;
        }
    }

    for(int i = 0; i <= m-2; i++)
        gs[m-1-suff[i]] = m-1-i;

    return gs;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.size(), m = pattern.size();
    vector<int> gs = goodSuffix(pattern);

    int s = 0;
    bool found = false;

    while(s <= n - m) {
        int j = m - 1;

        while(j >= 0 && pattern[j] == text[s + j])
            j--;

        if(j < 0) {
            cout << "Pattern found at index " << s << endl;
            found = true;
            s += gs[0];
        } else {
            s += gs[j];
        }
    }

    if(!found) cout << "Pattern not found";
}