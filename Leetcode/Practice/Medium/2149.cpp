/*Rearrange Array Elements by Sign
Example 1:
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &a)
    {
        int n = a.size(), i = 0, j = 1;
        vector<int> v(n);
        for (int b : a)
        {
            if (b > 0)
            {
                v[i] = b;
                i += 2;
            }
            else
            {
                v[j] = b;
                j += 2;
            }
        }
        return v;
    }
};

// isi mein ye hota ki positive aur negative equal nahi hain to
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            neg.push_back(a[i]);
        else
            pos.push_back(a[i]);
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    // aise hi else vala
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}

// iss case ke liye yahi most optimal solution hai aur uparvale case ke liye ye brute force hai