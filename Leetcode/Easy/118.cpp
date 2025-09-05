// Pascal's triamgle print karna hai
class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++)
        {
            long long res = 1;
            vector<int> a;
            a.push_back(1);
            for (int j = 1; j < i; j++)
            {
                res = res * (i - j);
                res /= j;
                a.push_back(res);
            }
            ans.push_back(a);
        }
        return ans;
    }
};
// TC - O(n*n)  SC - O(n^2)