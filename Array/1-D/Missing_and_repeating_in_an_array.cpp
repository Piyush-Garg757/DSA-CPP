/* ismein kya karna hai 1-n tak numbers honge array mein jismein se ek missing hoga aur ek repeat ho raha hoga to humein vo return karna hai*/

// Brute force -> nested loop vala hi O(n^2) jismein 1-n  har number ke liye iterate karenge array ko aur check karenge

// Better sol -> Hashing using unordered_map

// Optimal sol 1
/*
-> Array ka size n hota hai aur elements 1 se n ke beech hote hain.
-> Ek number repeat hota hai (maan lo R) aur ek number missing hota hai (maan lo M).
-> Array ke saare elements ka actual sum nikaalo → S.
-> 1 se n tak ka expected sum nikaalo
-> SN = n(n+1)/2.
-> Dono ka difference lo:
-> S - SN = R - M
-> (yeh pehli equation hai)
-> Ab array ke elements ka actual sum of squares nikaalo → S2.
-> 1 se n tak ka expected sum of squares nikaalo
-> S2N = n(n+1)(2n+1)/6.
-> Dono ka difference lo:
-> S2 - S2N = R² - M².
-> Identity use karo:
-> R² - M² = (R - M)(R + M).
-> Pehli equation se (R - M) already pata hai, use divide karke (R + M) nikaal lo.
-> Ab do equations mil gayi:
-> R - M
-> R + M
-> Inko solve karo:
-> R = ( (R - M) + (R + M) ) / 2
-> M = R - (R - M)
-> Is tarah bina extra space ke repeating aur missing number mil jaata hai.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long S = 0, S2 = 0;
    long long SN = 1LL * n * (n + 1) / 2;
    long long S2N = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += 1LL * a[i] * a[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << "Repeating number: " << x << "\n";
    cout << "Missing number: " << y << "\n";
    return 0;
}
// TC - O(n)  SC - O(1)