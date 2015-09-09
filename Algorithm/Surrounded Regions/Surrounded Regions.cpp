class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < col; i++) {
            bfs(board, 0, i);
            bfs(board, row - 1, i);
        }
        for (int i = 0; i < row; i++) {
            bfs(board, i, 0);
            bfs(board, i, col - 1);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    // bfs
    void bfs(vector<vector<char> >& board, int x, int y) {
        queue<pair<int, int> > q;
        helper(board, x, y, q);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            helper(board, x, y + 1, q);
            helper(board, x, y - 1, q);
            helper(board, x + 1, y, q);
            helper(board, x - 1, y, q);
        }
        return;
    }
    void helper(vector<vector<char> >& board, int x, int y, queue<pair<int, int> >& q) {
        int row = board.size();
        int col = board[0].size();
        if (x >= row || x < 0 || y >= col || y < 0 || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'Z';
        q.push(make_pair(x, y));
        return;
    }
};

