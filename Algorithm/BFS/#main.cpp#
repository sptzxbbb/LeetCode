#include "iostream"
#include <list>
using namespace std;
 
struct node {
	int x;
	int y;
	node(int a = 0, int b = 0) : x(a), y(b){};
};

void FindPath(int SIZE) {
	node begin(1, 1), des(SIZE, SIZE);
	int maze[SIZE + 2][SIZE + 2];

	for (int i = 1; i <= SIZE; ++i) {
		for (int j = 1; j <= SIZE; ++j) {
			cin >> maze[i][j];
		}
	}
  
	if (SIZE == 1) {
		cout << "1" << endl;
		return;
	}

	for (int i = 0; i <= SIZE + 1; ++i) {
		maze[0][i] = maze[SIZE + 1][i] = 1;
		maze[i][0] = maze[i][SIZE + 1] = 1;
	}

	node offset[4];
	offset[0].x = 0, offset[0].y = 1;  // up
	offset[1].x = 1, offset[1].y = 0;  // right
	offset[2].x = 0, offset[2].y = -1;  // down
	offset[3].x = -1, offset[3].y = 0;  // left

	const int NumOfNbr = 4;
	node cur(begin.x, begin.y), nbr;
	list<node> path;
	maze[begin.x][begin.y] = 2;
	path.push_back(cur);
	while (1) {
		for (int i = 0; i < NumOfNbr; ++i) {
			nbr.x = cur.x + offset[i].x;
			nbr.y = cur.y + offset[i].y;
			if (maze[nbr.x][nbr.y] == 0) {
				maze[nbr.x][nbr.y] = maze[cur.x][cur.y] + 1;
				if (nbr.x == des.x && nbr.y == des.y) {
					int length = maze[nbr.x][nbr.y] - 2;
					cout << length + 1 << endl;
					return;
				} else {
					path.push_back(nbr);
				}
			}
		}
		if (path.empty()) {
			cout << '0' << endl;
			return;
		} else {
			path.pop_front();
			if (path.size()) cur = path.front();
		}
	};
}

int main(int argc, char *argv[]) {
	int n;
	while (1) {
		cin >> n;
		if (!n) return 0;
		FindPath(n);
	};
}


// 0 0 1 1 1 1
// 1 0 1 1 1 1
// 0 0 0 0 1 1
// 0 0 1 1 1 1
// 0 0 0 1 1 1
// 0 1 0 0 0 0
