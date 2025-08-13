/*Find if Digit Game Can Be Won
Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.
Return true if Alice can win this game, otherwise, return false

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 99*/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s = 0, d = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 10)
                s += nums[i];
            else
                d += nums[i];
        }
        return !(d == s);
    }
};
// TC - O(n)  SC - O(1)