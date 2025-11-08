// First and last occurence
class Solution
{
public:
    vector<int> searchRange(vector<int> &a, int target)
    {
        vector<int> ans;
        int n = a.size();
        int low = 0, high = n - 1, ans1 = -1, ans2 = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] == target)
            {
                ans1 = mid;
                high = mid - 1;
            }
            else if (a[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] == target)
            {
                ans2 = mid;
                low = mid + 1;
            }
            else if (a[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
// TC - 2*O(log(N))  SC - O(1)