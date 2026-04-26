#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] == x) return m;
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int res = binarySearch(a, x);

    if(res != -1) cout << "Element found at index " << res;
    else cout << "Element not found";
}