/*Find N Unique Integers Sum up to Zero
Example 1:
Input: n = 5
Output: [-7,-1,1,3,4]

Example 2:
Input: n = 3
Output: [-1,0,1]

Example 3:
Input: n = 1
Output: [0]*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if (n % 2 != 0) {
            v.push_back(0);
            n--;
        }
        int k = 1;
        for (int i = 0; i < n; i = i + 2) {
            v.push_back(k);
            v.push_back(-k);
            k++;
        }
        return v;
    }
};
// TC - O(n)  SC - O(n/2)