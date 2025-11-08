/*Find the Number of Good Pairs I
You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
Return the total number of good pairs.

Example 1:
Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1
Output: 5
Explanation:
The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2)*/

// Brute force
class Solution
{
public:
    int numberOfPairs(vector<int> &a, vector<int> &b, int k)
    {
        int n = a.size(), m = b.size();
        for (int i = 0; i < m; i++)
        {
            b[i] *= k;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] % b[j] == 0)
                    count++;
            }
        }
        return count;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimised
class Solution
{
public:
    int numberOfPairs(vector<int> &a, vector<int> &b, int k)
    {
        unordered_map<int, int> freq;

        // Step 1: Precompute frequency of (b[j] * k)
        for (int x : b)
        {
            freq[x * k]++;
        }

        long long ans = 0;

        // Step 2: For each a[i], find all divisors and count matches
        for (int x : a)
        {
            for (int d = 1; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    // if divisor matches any (b[j]*k)
                    if (freq.count(d))
                        ans += freq[d];
                    // check complementary divisor (avoid double counting)
                    if (d != x / d && freq.count(x / d))
                        ans += freq[x / d];
                }
            }
        }

        return (int)ans;
    }
};
// TC - O(n * √max(a[i]))  SC - O(n)