// Find missing number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
class Solution
{
public:
    int missingNumber(vector<int> &a)
    {
        int n = a.size(), sum = 0, check = (n * (n + 1)) / 2;
        for (int i = 0; i < n; i++)
            sum += a[i];
        return check - sum;
    }
};
// TC - O(n)  SC - O(1)
// xor se bhi kar sakte the