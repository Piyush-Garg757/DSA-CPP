/*Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]*/

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &a)
    {
        int n = a.size();
        long long sn = 1LL * n * (n + 1) / 2;
        long long s2n = 1LL * n * (n + 1) * (2 * n + 1) / 6;
        long long s = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            s2 += 1LL * a[i] * a[i];
        }
        long long val1 = s - sn;
        long long val2 = (s2 - s2n) / val1;
        int x = (val1 + val2) / 2;
        int y = x - val1;
        return {x, y};
    }
};
// TC - O(n)  SC - O(1)