#include <bits/stdc++.h>
// #include "hero.cpp"  agar kisi aur file mein banaya hai class to iss file mein include kar sakte hain
using namespace std;

class hero
{
public: // ye properties kahi bhi acceess kar sakte hain
    string name;
    int health;
    void getscore()// getter
    {
        return health;
    }
    void setscore(int s)// setter
    {
        score = s;
    }

private: // ye properties bas class ke andar access kar sakte hain
    int score;
};
int main()
{
    hero h1;//Static allocation
    hero *h2=new hero;//Dynamic allocation
    // aur jab dynamically banaya ho to baar baar properties ya functions access karne ke liye (*h2).score  aise karo ya fir h2->score
    cout << sizeof(h1);
    // h1 ek object ban gaya hero class ka   aur jab int hoga ek hero ke andar  to h1 ka size 4 ata  but jab empty class hai to 1 byte memory allocate hoti hai
    return 0;
}