#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct pos {
    int x, y;
};

enum state {
    SAFE, UNSAFE, BLOCKED
};

bool isInside(int x, int y, vector<vector<state> >& board) {
    if (x >= 0 && x < (int)board.size() && y >= 0 && y < (int)board[0].size()) {
        return true;
    } else {
        return false;
    }
}

void handleQ(vector<pos>& queen, vector<vector<state> >& board, int& count) {
    int dirX[8] = {0, 0, 1, 1, 1, -1, -1, -1};
    int dirY[8] = {-1, 1, 1, -1, 0, -1, 1, 0};
    for (int i = 0; i < (int)queen.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int x = queen[i].x, y = queen[i].y;
            while (isInside(x + dirX[j], y + dirY[j], board) &&
                   board[x + dirX[j]][y + dirY[j]] != BLOCKED) {
                x += dirX[j];
                y += dirY[j];
                if (board[x][y] == SAFE) {
                    --count;
                    board[x][y] = UNSAFE;
                }
            }
        }
    }
}

void handleK(vector<pos>& knight, vector<vector<state> >& board, int& count) {
    int dirX[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dirY[8] = {-2, 2, -2, 2, -1, 1, -1, 1};
    for (int i = 0; i < (int)knight.size(); i++) {
        int x, y;
        for (int j = 0; j < 8; j++) {
            x = knight[i].x + dirX[j];
            y = knight[i].y + dirY[j];
            if (isInside(x, y, board) && board[x][y] == SAFE) {
                --count;
                board[x][y] = UNSAFE;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n, m, x, y, turn = 0;
    while (cin >> n >> m, n != 0 && m != 0) {
        vector<vector<state> > board(n, vector<state>(m, SAFE));
        int count = n * m;
        // queen
        int numQ;
        cin >> numQ;
        vector<pos> queen(numQ);
        for (int i = 0; i < numQ; i++) {
            cin >> x >> y;
            --x, --y;
            queen[i].x = x;
            queen[i].y = y;
            board[x][y] = BLOCKED;
        }
        // knight
        int numK;
        cin >> numK;
        vector<pos> knight(numK);
        for (int i = 0; i < numK; i++) {
            cin >> x >> y;
            --x, --y;
            knight[i].x = x;
            knight[i].y = y;
            board[x][y] = BLOCKED;
        }
        // pawn
        int numP;
        cin >> numP;
        vector<pos> pawn(numP);
        for (int i = 0; i < numP; i++) {
            cin >> x >> y;
            --x, --y;
            pawn[i].x = x;
            pawn[i].y = y;
            board[x][y] = BLOCKED;
        }
        count -= (numQ + numK + numP);
        handleQ(queen, board, count);
        handleK(knight, board, count);
        cout << "Board " << ++turn << " has " << count << " safe squares." << endl;
    }
    return 0;
}
