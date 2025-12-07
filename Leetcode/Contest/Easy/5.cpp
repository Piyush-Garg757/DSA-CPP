/*Sort Integers by Binary Reflection
You are given an integer array nums.
The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.
Sort the array in ascending order based on the binary reflection of each element. If two different numbers have the same binary reflection, the smaller original number should appear first.
Return the resulting sorted array.

Example 1:
Input: nums = [4,5,4]
Output: [4,4,5]
Explanation:
Binary reflections are:
4 -> (binary) 100 -> (reversed) 001 -> 1
5 -> (binary) 101 -> (reversed) 101 -> 5
4 -> (binary) 100 -> (reversed) 001 -> 1
Sorting by the reflected values gives [4, 4, 5].

Example 2:
Input: nums = [3,6,5,8]
Output: [8,3,6,5]
Explanation:
Binary reflections are:
3 -> (binary) 11 -> (reversed) 11 -> 3
6 -> (binary) 110 -> (reversed) 011 -> 3
5 -> (binary) 101 -> (reversed) 101 -> 5
8 -> (binary) 1000 -> (reversed) 0001 -> 1
Sorting by the reflected values gives [8, 3, 6, 5].
Note that 3 and 6 have the same reflection, so we arrange them in increasing order of original value.*/
class Solution
{
public:
    int reverseBinary(int x)
    {
        int rev = 0;
        while (x > 0)
        {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }
        return rev;
    }
    vector<int> sortByReflection(vector<int> &a)
    {
        vector<pair<int, int>> v;
        for (int x : a)
        {
            v.push_back({reverseBinary(x), x});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (auto &p : v)
            ans.push_back(p.second);

        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)