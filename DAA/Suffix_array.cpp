#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.size();
    vector<pair<string,int>> suffixes;

    for(int i = 0; i < n; i++)
        suffixes.push_back({s.substr(i), i});

    sort(suffixes.begin(), suffixes.end());

    cout << "Suffix Array:\n";
    for(auto x : suffixes)
        cout << x.second << " ";
}