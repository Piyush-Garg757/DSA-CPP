/*3248. Snake in Matrix
Solved
Easy
Topics
premium lock icon
Companies
Hint
There is a snake in an n x n matrix grid and can move in four possible directions. Each cell in the grid is identified by the position: grid[i][j] = (i * n) + j.
The snake starts at cell 0 and follows a sequence of commands.
You are given an integer n representing the size of the grid and an array of strings commands where each command[i] is either "UP", "RIGHT", "DOWN", and "LEFT". It's guaranteed that the snake will remain within the grid boundaries throughout its movement.
Return the position of the final cell where the snake ends up after executing commands.

Example 1:
Input: n = 2, commands = ["RIGHT","DOWN"]
Output: 3
Explanation:
0
2	3

0	1
2

Example 2:
Input: n = 3, commands = ["DOWN","RIGHT","UP"]
Output: 1
Explanation:
0	1	2
    4	5
6	7	8

0	1	2
3		5
6	7	8

0		2
3	4	5
6	7	8
*/
class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &a)
    {
        int li = 0, ri = 0;
        for (string s : a)
        {
            if (s == "DOWN")
                li++;
            else if (s == "RIGHT")
                ri++;
            else if (s == "LEFT")
                ri--;
            else
                li--;
        }
        return n * li + ri;
    }
};
// TC - O(n)  SC - O(1)