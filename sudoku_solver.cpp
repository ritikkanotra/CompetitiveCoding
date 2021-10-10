// @coder6147
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;
int MOD = 1000000007;

void init() {
    #ifndef ONLINE_JUDGE
    freopen("E:\\DATA\\C++ Programs\\input.txt", "r", stdin);
    freopen("E:\\DATA\\C++ Programs\\output.txt", "w", stdout);
    #endif
}

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    //check in row;
    for (int i = 0; i < 9; i++) {
        if (col != i && board[row][i] == num) {
            return false;
        }
    }
    //check in col;
    for (int i = 0; i < 9; i++) {
        if (row != i && board[i][col] == num) {
            return false;
        }
    }

    int i = (int)(row / 3) * 3;
    int j = (int)(col / 3) * 3;
    int a = i + 3;
    int b = j + 3;
    for (i = (int)(row / 3) * 3; i < a; i++) {
        for (j = (int)(col / 3) * 3; j < b; j++) {
            // cout << board[i][j] << " " << num << endl;
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;

}

bool solve(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        return true;
    }
    if (board[row][col] != '.') {
        if (col == 8) {
            return solve(board, row + 1, 0);
        }
        else {
            return solve(board, row, col + 1);
        }
    }
    for (int i = 1; i <= 9; i++) {
        char ch = '0' + i;
        if (isValid(board, row, col, ch)) {
            board[row][col] = ch;
            int t_row, t_col;
            if (col == 8) {
                t_row = row + 1;
                t_col = 0;
            }
            else {
                t_row = row;
                t_col = col + 1;
            }
            if (solve(board, t_row, t_col)) {
                return true;
            }
        }
    }
    board[row][col] = '.';

    // cout << isValid(board, 2, 1, '0' + 2) << endl;

    return false;

}

void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0, 0);
}

int main() {
    init();
    char temp;
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> tvec;
        for (int j = 0; j < 9; j++) {
            cin >> temp;
            tvec.pb(temp);
        }
        board.pb(tvec);
    }
    solveSudoku(board);
    for (auto vec: board) {
        for (char ch: vec) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// INPUT:

// . . 9 7 4 8 . . . 
// 7 . . . . . . . . 
// . 2 . 1 . 9 . . . 
// . . 7 . . . 2 4 . 
// . 6 4 . 1 . 5 9 . 
// . 9 8 . . . 3 . . 
// . . . 8 . 3 . 2 . 
// . . . . . . . . 6 
// . . . 2 7 5 9 . . 