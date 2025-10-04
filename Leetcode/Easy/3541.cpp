/*Find Most Frequent Vowel and Consonant

Example 1:
Input: s = "successes"
Output: 6
Explanation:
The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
The output is 2 + 4 = 6.*/
class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> mpp;
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        for (auto i : mpp)
        {
            if (i.first == 'a' || i.first == 'e' || i.first == 'i' ||
                i.first == 'o' || i.first == 'u')
            {
                if (i.second > ans1)
                    ans1 = i.second;
            }
            else
            {
                if (i.second > ans2)
                    ans2 = i.second;
            }
        }
        return ans1 + ans2;
    }
};
// TC - O(n)  SC - O(n)