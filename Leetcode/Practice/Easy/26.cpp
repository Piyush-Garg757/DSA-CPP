// Remove Duplicates from Sorted Array
// ismein set vali approach use nahi karenge kyuki already sorted hai so uski need nahi hai

// Two pointer approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
// TC - O(n) SC - O(1)
