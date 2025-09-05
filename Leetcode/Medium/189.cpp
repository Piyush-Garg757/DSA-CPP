// Right rotate an array by k steps
class Solution {
public:
    void reverse(vector<int>& a, int s, int e) {
        while (s <= e) {
            int temp = a[s];
            a[s++] = a[e];
            a[e--] = temp;
        }
    }
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k %= n;
        reverse(a, 0, n - 1);
        reverse(a, 0, k - 1);
        reverse(a, k, n - 1);
    }
};
// TC - O(n)  SC - O(1)