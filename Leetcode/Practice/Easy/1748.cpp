/*Sum of Unique Elements
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
Return the sum of all the unique elements of nums.

Example 1:
Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.

Example 2:
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.*/
class Solution
{
public:
    int sumOfUnique(vector<int> &a)
    {
        int n = a.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[a[i]]++;
        }
        int sum = 0;
        for (auto i : mpp)
        {
            if (i.second == 1)
                sum += i.first;
        }
        return sum;
    }
};
// TC - O(n)  SC - O(n)

class Solution
{
public:
    int sumOfUnique(vector<int> &a)
    {
        unordered_map<int, int> freq;
        int sum = 0;
        for (int x : a)
        {
            if (++freq[x] == 1)
                sum += x;
            else if (freq[x] == 2)
                sum -= x;
        }
        return sum;
    }
};
// TC - O(n)  SC - O(n)
