#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        bool ok = false;
        next(0, board, ok);
    }
    void next(int step, vector<vector<char> >& board, bool& ok) {
        if (81 == step) {
            ok = true;
            return;
        }
        // 012 345 678
        int row = step / 9;
        int col = step % 9;

         if (board[row][col] != '.') {
             next(step + 1, board, ok);
             return;
         }

        vector<bool> num(10, true);
        vector<char> candidate;
        // remove numbers taken in the same row and col
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                num[board[row][i] - '0'] = false;
            }
            if (board[i][col] != '.') {
                num[board[i][col] - '0'] = false;
            }
        }
        // remove numbers taken in the same JiuGongGe
        int m = row / 3 * 3, n = col / 3 * 3;
        for (int i = m; i < m + 3; i++) {
            for (int j = n; j < n + 3; j++) {
                if (board[i][j] != '.') {
                    num[board[i][j] - '0'] = false;
                }
            }
        }
        // filter out the impossibles
        for (int i = 1; i <= 9; i++) {
            if (true == num[i]) {
                candidate.push_back('0' + i);
            }
        }
        int size = candidate.size();
        for (int i = 0; i < size; i++) {
            board[row][col] = candidate[i];
            next(step + 1, board, ok);
            if (ok == true) {
                return;
            }
            board[row][col] = '.';
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    string s[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> > sudoku;
    for (int i = 0; i < 9; i++) {
        vector<char> ele;
        for (int j = 0; j < s[i].size(); j++) {
            ele.push_back(s[i][j]);
        }
        sudoku.push_back(ele);
    }
    Solution k;
    k.solveSudoku(sudoku);
    return 0;
}
