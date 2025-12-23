/* ismein hum binary search hi lagate hain but check karte hain ki left part ssorted hain mid ke ya right kyuki peak diagram banta hai  ismein jis se ye to sure ho jate hain ki ek part to sorted hoga hi*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int k)
{
    int n = a.size();
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            break;
        }
        // left part sorted
        if (a[low] <= a[mid])
        {
            if (a[low] <= k && k <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // right part sorted
        else
        {
            if (a[mid] <= k && k <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << search(a, k);
    return 0;
}
// TC - O(logn)  SC - O(1)