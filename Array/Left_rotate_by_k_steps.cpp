#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the value of k\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}