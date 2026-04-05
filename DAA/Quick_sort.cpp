#include <bits/stdc++.h>
using namespace std;
void quicksort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int pivot = a[low];
    int i = low + 1, j = high;
    while (true)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    quicksort(a, low, j - 1);
    quicksort(a, j + 1, high);
}
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
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}