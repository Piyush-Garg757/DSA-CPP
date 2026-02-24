#include<bits/stdc++.h>
int findMinimumDays(int max_products, vector<int> tasks) {
    int sz = tasks.size();
    vector<int> p(sz);
    int current_sum = 0;
    for (int i = 0; i < sz; i++) {
        current_sum += tasks[i];
        p[i] = current_sum;
        if (p[i] > max_products) {
            return -1;
        }
    }
    vector<int> max_a(sz);
    max_a[sz - 1] = max_products - p[sz - 1];
    
    for (int i = sz - 2; i >= 0; i--) {
        int diff = max_products - p[i];
        max_a[i] = min(diff, max_a[i + 1]);
    }
    int curr_a = 0;
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        if (tasks[i] == 0) {
            if (p[i] + curr_a < 0) {
                int needed = -(p[i] + curr_a);
                int can_add = max_a[i] - curr_a;
                if (needed > can_add) {
                    return -1;
                }
                curr_a += can_add;
                ans++;
            }
        }
    }
    return ans;
}
int main()