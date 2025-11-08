/*Decode XORed Array
There is a hidden integer array arr that consists of n non-negative integers.
It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].
You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].
Return the original array arr. It can be proved that the answer exists and is unique.

Example 1:
Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]*/
class Solution
{
public:
    vector<int> decode(vector<int> &a, int f)
    {
        int n = a.size();
        vector<int> ans(n + 1);
        ans[0] = f;
        for (int i = 0; i < n; i++)
        {
            ans[i + 1] = a[i] ^ ans[i];
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

class Solution
{
public:
    vector<int> decode(vector<int> &a, int f)
    {
        a.insert(a.begin(), f);
        for (int i = 1; i < a.size(); i++)
        {
            a[i] = a[i - 1] ^ a[i];
        }
        return a;
    }
};
// TC - O(n)  SC - O(n)