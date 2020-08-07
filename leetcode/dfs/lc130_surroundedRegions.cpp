#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board)
    {
        int i = 0;
        int j = 0;
        int rows = board.size();
        int cols = board[0].size();

        for (i = 0; i < rows; i++) {
            check(board, i, 0, rows, cols);
            if (cols > 1) {
                check(board, i, cols - 1, rows, cols);
            }
        }
        for (j = 1; j + 1 < cols; j++) {
            check(board, 0, j, rows, cols);
            if (rows > 1) {
                check(board, rows - 1, j, rows, cols);
            }
        }

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void check(vector<vector<char>> &vec, int i, int j, int rows, int cols)
    {
        if (vec[i][j] == 'O') {
            vec[i][j] = '1';
            if (i > 1) {
                check(vec, i - 1, j, rows, cols);
            }
            if (j > 1) {
                check(vec, i, j - 1, rows, cols);
            }
            if (i + 1 < rows) {
                check(vec, i + 1, j, rows, cols);
            }
            if (j + 1 < cols) {
                check(vec, i, j + 1, rows, cols);
            }
        }
    }
};