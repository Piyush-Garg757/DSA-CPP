/*Number of Employees Who Met the Target
There are n employees in a company, numbered from 0 to n - 1. Each employee i has worked for hours[i] hours in the company.
The company requires each employee to work for at least target hours.
You are given a 0-indexed array of non-negative integers hours of length n and a non-negative integer target.
Return the integer denoting the number of employees who worked at least target hours.

Example 1:
Input: hours = [0,1,2,3,4], target = 2
Output: 3*/
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &a, int k)
    {
        int count = 0, n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= k)
                count++;
        }
        return count;
    }
};
// TC - O(n)  SC - O(1)