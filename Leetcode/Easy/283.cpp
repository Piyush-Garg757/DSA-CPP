// move zeroes to end
class Solution
{
public:
    void moveZeroes(vector<int> &a)
    {
        int n = a.size(), j = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;
        for (int i = j + 1; i < n; i++)
        {
            if (a[i] != 0)
                swap(a[i], a[j++]);
        }
    }
};
// TC - O(n)  SC - O(1)