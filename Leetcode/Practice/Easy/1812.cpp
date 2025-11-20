/*Determine Color of a Chessboard Square
You are given coordinates, a string that represents the coordinates of a square of the chessboard. Below is a chessboard for your reference.
Return true if the square is white, and false if the square is black.
The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first, and the number second.

Example 1:
Input: coordinates = "a1"
Output: false
Explanation: From the chessboard above, the square with coordinates "a1" is black, so return false.

Example 2:
Input: coordinates = "h3"
Output: true
Explanation: From the chessboard above, the square with coordinates "h3" is white, so return true.*/
class Solution
{
public:
    bool squareIsWhite(string a)
    {
        return ((a[0] - 'a' + 1) + (a[1] - '0')) % 2;
    }
};
// TC - O(1)  SC - O(1)