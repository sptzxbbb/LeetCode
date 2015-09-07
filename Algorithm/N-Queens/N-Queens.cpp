#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> board;
        // initial the board
        bool col_check[n];
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            board.push_back(row);
            col_check[i] = true;
        }
        dfs(board, 0, n, col_check);
        return result;
    }

    void dfs(vector<string>& board, int row, int n, bool* col_check) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (col_check[col] &&
                check_diagnoal(board, row, col, n)) {
                board[row][col] = 'Q';
                col_check[col] = false;
                dfs(board, row + 1, n, col_check);
                col_check[col] = true;
                board[row][col] = '.';
            }
        }
        return;
    }

    bool check_diagnoal(vector<string>& board, int row, int col, int n) {
        int left = col, right = col;
        for (int _row = row - 1; _row >= 0; _row--) {
            --left;
            ++right;
            if (left >= 0 && 'Q' == board[_row][left]) {
                return false;
            }
            if (right <= n - 1 && 'Q' == board[_row][right]) {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string> > result;
};

int main(int argc, char *argv[]) {
    Solution k;
    vector<vector<string> > ans = k.solveNQueens(5);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
