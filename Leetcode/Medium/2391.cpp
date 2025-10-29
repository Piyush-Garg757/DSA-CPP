/*Minimum Amount of Time to Collect Garbage
You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.
You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.
Return the minimum number of minutes needed to pick up all the garbage.

Example 1:
Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.

Example 2:
Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.*/

// Brute foece (First approach which came to my mind)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int garbageCollection(vector<string> &a, vector<int> &b)
    {
        int n = a.size();
        int g = 0, p = 0, m = 0;
        int cg = 0, cp = 0, cm = 0;
        for (int i = 1; i < n - 1; i++)
        {
            b[i] += b[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            unordered_map<char, int> mpp;
            for (char j : a[i])
            {
                mpp[j]++;
            }
            if (mpp.count('G'))
            {
                if (cg == 0 && i > 0)
                {
                    g += b[i - 1];
                    cg = 1;
                }
                else if (cg == 0 && i == 0)
                    cg = 1;
                g += mpp['G'];
            }
            if (mpp.count('P'))
            {
                if (cp == 0 && i > 0)
                {
                    p += b[i - 1];
                    cp = 1;
                }
                else if (cp == 0 && i == 0)
                    cp = 1;
                p += mpp['P'];
            }
            if (mpp.count('M'))
            {
                if (cm == 0 && i > 0)
                {
                    m += b[i - 1];
                    cm = 1;
                }
                else if (cm == 0 && i == 0)
                    cm = 1;
                m += mpp['M'];
            }
        }
        return p + g + m;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimised + More readable
class Solution
{
public:
    int getVal(vector<int> &b, int i)
    {
        if (i == 0)
            return 0;
        else
            return b[i - 1];
    }
    int garbageCollection(vector<string> &a, vector<int> &b)
    {
        int n = a.size();
        for (int i = 1; i < n - 1; i++)
        {
            b[i] += b[i - 1];
        }
        int g = 0, p = 0, m = 0;
        int lastG = 0, lastP = 0, lastM = 0;
        for (int i = 0; i < n; i++)
        {
            for (char c : a[i])
            {
                if (c == 'G')
                {
                    g++;
                    lastG = i;
                }
                else if (c == 'P')
                {
                    p++;
                    lastP = i;
                }
                else if (c == 'M')
                {
                    m++;
                    lastM = i;
                }
            }
        }
        int total =
            g + p + m + getVal(b, lastG) + getVal(b, lastP) + getVal(b, lastM);
        return total;
    }
};
// TC - O(n^2)  SC - O(1)