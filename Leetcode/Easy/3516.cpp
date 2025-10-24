/*Find Closest Person
Example 1:
Input: x = 2, y = 7, z = 4
Output: 1
Explanation:
Person 1 is at position 2 and can reach Person 3 (at position 4) in 2 steps.
Person 2 is at position 7 and can reach Person 3 in 3 steps.
Since Person 1 reaches Person 3 first, the output is 1.*/
class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        if (abs(z - y) > abs(z - x))
            return 1;
        else if (abs(z - y) == abs(z - x))
            return 0;
        return 2;
    }
};
// TC - O(1)  SC - O(1)