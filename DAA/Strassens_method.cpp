#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> sub(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    if (n == 1)
        return {{A[0][0] * B[0][0]}};

    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12 = A11, A21 = A11, A22 = A11;
    vector<vector<int>> B11(k, vector<int>(k)), B12 = B11, B21 = B11, B22 = B11;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    auto M1 = strassen(add(A11, A22, k), add(B11, B22, k), k);
    auto M2 = strassen(add(A21, A22, k), B11, k);
    auto M3 = strassen(A11, sub(B12, B22, k), k);
    auto M4 = strassen(A22, sub(B21, B11, k), k);
    auto M5 = strassen(add(A11, A12, k), B22, k);
    auto M6 = strassen(sub(A21, A11, k), add(B11, B12, k), k);
    auto M7 = strassen(sub(A12, A22, k), add(B21, B22, k), k);

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
        }

    return C;
}
int main()
{
    int n;
    cout << "Enter size of matrix\n";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    vector<vector<int>> result = strassen(A, B, n);
    cout << "Result Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}