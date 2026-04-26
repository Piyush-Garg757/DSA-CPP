#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int h) {
    int p = a[h], i = l - 1;
    for(int j = l; j < h; j++) {
        if(a[j] < p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int h) {
    if(l < h) {
        int pi = partition(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for(int x : a) cout << x << " ";
}