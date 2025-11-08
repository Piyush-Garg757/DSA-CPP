// Valid Perfect Square
class Solution
{
public:
    bool isPerfectSquare(int n)
    {
        bool flag = false;
        for (long long i = 1; i * i <= n; i++)
        {
            if (i * i == n)
                flag = true;
        }
        return flag;
    }
};
// TC - O(N)  SC - O(1)