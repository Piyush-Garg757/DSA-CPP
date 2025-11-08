/*2114. Maximum Number of Words Found in Sentences
Example 1:
Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation:
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.*/
class Solution
{
public:
    int mostWordsFound(vector<string> &a)
    {
        int n = a.size(), maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (char j : a[i])
            {
                if (j == ' ')
                    count++;
            }
            maxi = max(maxi, count + 1);
        }
        return maxi;
    }
};
// TC - O(n^2)  SC - O(1)