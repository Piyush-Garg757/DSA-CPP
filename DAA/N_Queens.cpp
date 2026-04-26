#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for(int i = 0; i < col; i++)
        if(board[row][i] == 'Q') return false;

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 'Q') return false;

    for(int i = row, j = col; i < n && j >= 0; i++, j--)
        if(board[i][j] == 'Q') return false;

    return true;
}

bool solve(vector<string>& board, int col, int n) {
    if(col == n) return true;

    for(int i = 0; i < n; i++) {
        if(isSafe(board, i, col, n)) {
            board[i][col] = 'Q';
            if(solve(board, col + 1, n)) return true;
            board[i][col] = '.';
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));

    if(solve(board, 0, n)) {
        cout << "Solution:\n";
        for(auto &row : board) {
            for(char c : row) cout << c << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }
}