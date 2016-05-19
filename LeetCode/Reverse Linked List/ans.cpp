class Solution {
  public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) {
            return false;
        }
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(),false));
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(findWord(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool findWord(vector<vector<char> > &board, vector<vector<bool> > &visited, int row, int col, string &word, int index) {
        if(index==word.size()) {
            return true;
        }
        if(!isValid(board, row, col) || visited[row][col] || board[row][col]!=word[index]) {
            return false;
        }
        visited[row][col] = true;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            if (findWord(board, visited, row + x[i], col + y[i], word, index + 1)) {
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool isValid(vector<vector<char> >& board, int row, int col) {
        return row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
    }
};