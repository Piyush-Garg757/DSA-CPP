#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double brute(vector<Point>& p, int l, int r) {
    double d = 1e9;
    for(int i = l; i <= r; i++)
        for(int j = i + 1; j <= r; j++)
            d = min(d, dist(p[i], p[j]));
    return d;
}

double stripClosest(vector<Point>& strip, double d) {
    double mn = d;
    sort(strip.begin(), strip.end(), [](Point a, Point b){ return a.y < b.y; });

    for(int i = 0; i < strip.size(); i++)
        for(int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < mn; j++)
            mn = min(mn, dist(strip[i], strip[j]));

    return mn;
}

double closestUtil(vector<Point>& p, int l, int r) {
    if(r - l <= 3) return brute(p, l, r);

    int m = (l + r) / 2;
    Point mid = p[m];

    double dl = closestUtil(p, l, m);
    double dr = closestUtil(p, m + 1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for(int i = l; i <= r; i++)
        if(abs(p[i].x - mid.x) < d)
            strip.push_back(p[i]);

    return min(d, stripClosest(strip, d));
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> p(n);
    cout << "Enter points (x y):\n";
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    sort(p.begin(), p.end(), [](Point a, Point b){ return a.x < b.x; });

    double ans = closestUtil(p, 0, n - 1);

    cout << "Minimum distance: " << ans;
}