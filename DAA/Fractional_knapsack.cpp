#include <bits/stdc++.h>
using namespace std;

struct Item {
    int wt, val;
};

bool cmp(Item a, Item b) {
    return (double)a.val / a.wt > (double)b.val / b.wt;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> a(n);

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++) cin >> a[i].wt;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) cin >> a[i].val;

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    sort(a.begin(), a.end(), cmp);

    double profit = 0.0;

    for(int i = 0; i < n; i++) {
        if(W >= a[i].wt) {
            profit += a[i].val;
            W -= a[i].wt;
        } else {
            profit += (double)a[i].val * W / a[i].wt;
            break;
        }
    }

    cout << "Maximum profit: " << profit;
}