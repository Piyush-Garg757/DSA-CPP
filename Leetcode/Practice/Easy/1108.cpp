/*Defanging an IP Address
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"*/

// Brute force
class Solution
{
public:
    string defangIPaddr(string address)
    {
        for (int i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                address.insert(i, "[");
                i += 1;
                address.insert(i + 1, "]");
                i += 1;
            }
        }
        return address;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimal
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res;
        for (char c : address)
        {
            if (c == '.')
                res += "[.]";
            else
                res += c;
        }
        return res;
    }
};
// TC - O(n)  SC - O(n)