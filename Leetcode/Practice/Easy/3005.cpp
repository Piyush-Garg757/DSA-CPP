/* Count Elements With Maximum Frequency
Example 1:
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
Example 2:
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[a[i]]++;
        }
        int maxfreq = 0, count = 0;
        for (auto i : mpp) {
            maxfreq = max(maxfreq, i.second);
        }
        for (auto i : mpp) {
            if (i.second == maxfreq)
                count += i.second;
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)