#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, int i, int sum, int target, vector<int>& subset) {
    if(sum == target) {
        cout << "Subset: ";
        for(int x : subset) cout << x << " ";
        cout << endl;
        return;
    }
    if(i == a.size() || sum > target) return;

    subset.push_back(a[i]);
    solve(a, i + 1, sum + a[i], target, subset);

    subset.pop_back();
    solve(a, i + 1, sum, target, subset);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;
    solve(a, 0, 0, target, subset);
}