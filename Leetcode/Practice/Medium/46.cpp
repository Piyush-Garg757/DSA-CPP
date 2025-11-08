// permutations
/*print all permutations*/

class Solution {
public:
    void permutations(vector<int>& a, int n, vector<vector<int>>& v,int index) {
        if (index >= n) {
            v.push_back(a);
            return;
        }
        for (int j = index; j < n; j++) {
            swap(a[j], a[index]);
            permutations(a, n, v, index + 1);
            swap(a[j], a[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> v;
        int n = a.size();
        permutations(a, n, v, 0);
        return v;
    }
};
// TC - O(n*n!)  SC - O(n)