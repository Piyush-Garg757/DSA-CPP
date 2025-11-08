// Two Sum II - Input Array Is Sorted
/*Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3]*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int target)
    {
        vector<int> ans;
        int n = a.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (a[i] + a[j] > target)
                j--;
            else if (a[i] + a[j] < target)
                i++;
            else
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)