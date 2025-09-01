// next permutation
class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int n = a.size(), index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1)
            reverse(a.begin(), a.end());
        else
        {
            for (int i = n - 1; i >= index; i--)
            {
                if (a[i] > a[index])
                {
                    swap(a[i], a[index]);
                    break;
                }
            }
            reverse(a.begin() + index + 1, a.end());
        }
    }
};
// TC - O(n)  SC - O(1)