class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int row = board.size();
        int col = board[0].size();
        vector<vector< bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (next(board, i, j, visit, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool next(vector<vector<char> >& board, int row, int col, vector<vector<bool> >& visit, string word, int step) {
        if (step == word.size()) {
            return true;
        }
        if (!isValid(board, row, col) || visit[row][col] || board[row][col] != word[step]) {
            return false;
        }
        visit[row][col] = true;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            if (next(board, row + x[i], col + y[i], visit, word, step + 1)) {
                return true;
            }
        }
        visit[row][col] = false;
        return false;
    }

    bool isValid(vector<vector<char> >& board, int row, int col) {
        return row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
    }
};