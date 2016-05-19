#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

enum stateType {
    OCCUPIED, FREE
};

enum dirType {
    UP, DOWN, LEFT, RIGHT
};

class mapType {
  public:
    void setSize(int _height, int _width) {
        for (int i = 0; i < _height; i++) {
            vector<int> row(_width, FREE);
            map.push_back(row);
        }
        left = 0;
        right = _width - 1;
        up = 0;
        down = _height - 1;
        height = _height;
        width = _width;
        return;
    }

    void put(int x, int y) {
        map[x][y] = OCCUPIED;
        return;
    }
    /* when queue Judge is not empty
       take thefirst element e in queue Judge
       1. if the next position of e is FREE or OCCUPIED, put it into corresponding stack toMove[i]
       2. if the next position of e is OCCUPIED, put the next pos into queue Judge
       3. if the next position of e is Wall, set canMove false and break
       if (canMove)
       move the box in stack toMove
       else
       return
    */
    void moveRight(int dis) {
        bool canMove = true;
        int _right = right;
        for (int i = 0; i < dis; i++) {
            // the box that should be moved at row i
            stack<int> toMove[map.size()];
            queue<pair<int, int> > judge;
            for (int i = 0; i < height; i++) {
                if (map[i][_right] == OCCUPIED) {
                    judge.push(make_pair(i, _right));
                }
            }
            while (!judge.empty()) {
                pair<int, int> e = judge.front();
                judge.pop();
                // hit the left wall
                if (e.second - 1 < left) {
                    canMove = false;
                    break;
                } else {
                    toMove[e.first].push(e.second);
                    // push adjacent box
                    if (map[e.first][e.second - 1] == OCCUPIED) {
                        judge.push(make_pair(e.first, e.second - 1));
                    }
                }
            }
            if (!canMove) {
                return;
            } else {
                for (int i = 0; i < height; i++) {
                    // move the box
                    while (!toMove[i].empty()) {
                        int col = toMove[i].top();
                        toMove[i].pop();
                        map[i][col] = FREE;
                        map[i][col - 1] = OCCUPIED;
                    }
                }
            }
            --_right;
        }
        return;
    }

    void moveLeft(int dis) {
        bool canMove = true;
        int _left = left;
        for (int i = 0; i < dis; i++) {
            // the box that should be moved at row i
            stack<int> toMove[map.size()];
            queue<pair<int, int> > judge;
            for (int i = 0; i < height; i++) {
                if (map[i][_left] == OCCUPIED) {
                    judge.push(make_pair(i, _left));
                }
            }
            while (!judge.empty()) {
                pair<int, int> e = judge.front();
                judge.pop();
                // hit the left wall
                if (e.second + 1 > right) {
                    canMove = false;
                    break;
                } else {
                    toMove[e.first].push(e.second);
                    // push adjacent box
                    if (map[e.first][e.second + 1] == OCCUPIED) {
                        judge.push(make_pair(e.first, e.second + 1));
                    }
                }
            }
            if (!canMove) {
                return;
            } else {
                for (int i = 0; i < height; i++) {
                    // move the box
                    while (!toMove[i].empty()) {
                        int col = toMove[i].top();
                        toMove[i].pop();
                        map[i][col] = FREE;
                        map[i][col + 1] = OCCUPIED;
                    }
                }
            }
            ++_left;
        }
        return;

    }
    void moveUp(int dis) {
        bool canMove = true;
        int _up = up;
        for (int i = 0; i < dis; i++) {
            // the box that should be moved at row i
            stack<int> toMove[width];
            queue<pair<int, int> > judge;
            for (int i = 0; i < width; i++) {
                if (map[_up][i] == OCCUPIED) {
                    judge.push(make_pair(_up, i));
                }
            }
            while (!judge.empty()) {
                pair<int, int> e = judge.front();
                judge.pop();
                // hit the down wall
                if (e.first + 1 > down) {
                    canMove = false;
                    break;
                } else {
                    toMove[e.second].push(e.first);
                    // push adjacent box
                    if (map[e.first + 1][e.second] == OCCUPIED) {
                        judge.push(make_pair(e.first + 1, e.second));
                    }
                }
            }
            if (!canMove) {
                return;
            } else {
                for (int i = 0; i < width; i++) {
                    // move the box
                    while (!toMove[i].empty()) {
                        int row = toMove[i].top();
                        toMove[i].pop();
                        map[row][i] = FREE;
                        map[row + 1][i] = OCCUPIED;
                    }
                }
            }
            ++_up;
        }
        return;
    }

    void moveDown(int dis) {
        bool canMove = true;
        int _down = down;
        for (int i = 0; i < dis; i++) {
            // the box that should be moved at row i
            stack<int> toMove[width];
            queue<pair<int, int> > judge;
            for (int i = 0; i < width; i++) {
                if (map[_down][i] == OCCUPIED) {
                    judge.push(make_pair(_down, i));
                }
            }
            while (!judge.empty()) {
                pair<int, int> e = judge.front();
                judge.pop();
                // hit the down wall
                if (e.first - 1 < up) {
                    canMove = false;
                    break;
                } else {
                    toMove[e.second].push(e.first);
                    // push adjacent box
                    if (map[e.first - 1][e.second] == OCCUPIED) {
                        judge.push(make_pair(e.first - 1, e.second));
                    }
                }
            }
            if (!canMove) {
                return;
            } else {
                for (int i = 0; i < width; i++) {
                    // move the box
                    while (!toMove[i].empty()) {
                        int row = toMove[i].top();
                        toMove[i].pop();
                        map[row][i] = FREE;
                        map[row - 1][i] = OCCUPIED;
                    }
                }
            }
            --_down;
        }
        return;
    }

    void print(void) const {
        for (int i = 0; i < (int)map.size(); i++) {
            for (int j = 0; j < (int)map[0].size(); j++) {
                if (map[i][j] == OCCUPIED) {
                    cout << " (" << i << ',' << j << ")";
                }
            }
        }
        cout << '.' << endl;
    }

  private:
    vector<vector<int> > map;
    int left, right, up, down;
    int height, width;
};

int main(int argc, char *argv[]) {
    int height, width, numCase = 0;
    while (cin >> height >> width && height != 0) {
        mapType map;
        map.setSize(height, width);
        int n, x, y;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            map.put(x, y);
        }
        string command;
        while (cin >> command && command != "done") {
            int dis;
            cin >> dis;
            if (command == "up") {
                map.moveDown(dis);
            } else if (command == "down") {
                map.moveUp(dis);
            } else if (command == "left") {
                map.moveRight(dis);
            } else {
                map.moveLeft(dis);
            }
        }
        cout << "Data set " << ++numCase << " ends with boxes at locations";
        map.print();
    }
    return 0;
}

// 12 16
// 7 1 13 3 2 6 2 6 4 6 6 7 6 8 9
// down 3
// left 14
// done
// 4 4
// 3 1 0 2 1 2 3
// right 3
// up 2
// left 1
// done
// 0 0

// Data set 1 ends with boxes at locations (3,1) (3,2) (6,0) (6,1) (6,2) (7,2) (8,2).
// Data set 2 ends with boxes at locations (0,2) (1,1) (1,2).