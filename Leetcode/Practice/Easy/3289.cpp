/*The Two Sneaky Numbers of Digitville
Example 1:
Input: nums = [0,1,1,0]
Output: [0,1]
Explanation:
The numbers 0 and 1 each appear twice in the array.*/
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &a)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < a.size(); i++)
        {
            mpp[a[i]]++;
        }
        for (auto i : mpp)
        {
            if (i.second == 2)
                ans.push_back(i.first);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)