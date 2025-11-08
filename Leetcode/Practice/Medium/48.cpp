// Rotate image
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(a[i][j], a[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(a[i][j], a[i][n - 1 - j]);
            }
        }
    }
};
// TC - O(n^2)  SC - O(1)