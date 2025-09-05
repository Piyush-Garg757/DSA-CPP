// Pascals triangle hi but ismein row number diya hai wahi row print karna hai
class Solution {
public:
    vector<int> getRow(int rowindex) {
        vector<int> ans;
        ans.push_back(1);
        long long res = 1;
        for (int i = 1; i < rowindex + 1; i++) {
            res *= (rowindex - i + 1);
            res /= i;
            ans.push_back(res);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)