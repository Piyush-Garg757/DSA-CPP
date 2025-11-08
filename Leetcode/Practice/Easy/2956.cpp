/*Find Common Elements Between Two Arrays
You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:
answer1 : the number of indices i such that nums1[i] exists in nums2.
answer2 : the number of indices i such that nums2[i] exists in nums1.
Return [answer1,answer2].

Example 1:
Input: nums1 = [2,3,2], nums2 = [1,2]
Output: [2,1]*/

// Brite to vahi 0(n^2)

// Better
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> setB(b.begin(), b.end());
        int count1 = 0, count2 = 0;
        for (int x : a)
            if (setB.count(x))
                count1++;
        for (int x : b)
            if (setA.count(x))
                count2++;
        return {count1, count2};
    }
};
// Tc - O(n+m)  SC - O(n+m)

// Optimal
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0, count1 = 0, count2 = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                count1++;
                i++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        i = j = 0;
        while (i < b.size() && j < a.size())
        {
            if (b[i] == a[j])
            {
                count2++;
                i++;
            }
            else if (b[i] < a[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return {count1, count2};
    }
};
// TC - O(nlogn) + O(mlogm)  SC - O(1)