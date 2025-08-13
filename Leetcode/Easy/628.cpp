// Maximum product of three numbers
/*Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [-1,-2,-3]
Output: -6*/

#include <limits>
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max = INT_MIN, smax = INT_MIN, tmax = INT_MIN, min = INT_MAX,
            smin = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                tmax = smax;
                smax = max;
                max = nums[i];
            } else if (nums[i] > smax) {
                tmax = smax;
                smax = nums[i];
            } else if (nums[i] > tmax) {
                tmax = nums[i];
            }
            if (nums[i] < min) {
                smin = min;
                min = nums[i];
            } else if (nums[i] < smin) {
                smin = nums[i];
            }
        }
        int p1 = min * smin * max, p2 = max * smax * tmax;
        if (p1 > p2)
            return p1;
        return p2;
    }
};
// TC - O(n)  SC - O(1)