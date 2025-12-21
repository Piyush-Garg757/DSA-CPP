/*Permutation Sequence
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

Example 3:
Input: n = 3, k = 1
Output: "123"*/

class Solution
{
public:
    int fact(int n)
    {
        if (n <= 1)
            return 1;
        return n * fact(n - 1);
    }
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        string s = "";
        k--;
        while (n > 0)
        {
            int check = fact(n - 1);
            int f_no = k / check;
            s += to_string(nums[f_no]);
            nums.erase(nums.begin() + f_no);
            k = k % check;
            n--;
        }
        return s;
    }
};
// TC - O(n^2)  SC - O(n)