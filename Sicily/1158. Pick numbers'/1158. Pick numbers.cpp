#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dfs(vector<vector<int> >& matrix, int x, int y, int sum, int& minSum) {
    sum += matrix[x][y];
    // bottom-right corner
    if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
        if (minSum > sum && sum > 0) {
            minSum = sum;
        }
        return;
    }
    // move right
    if (y + 1 < matrix[0].size()) {
        dfs(matrix, x, y + 1, sum, minSum);
    }
    // move down
    if (x + 1 < matrix.size()) {
        dfs(matrix, x + 1, y, sum, minSum);
    }
    return;
}

int main(int argc, char *argv[]) {
    int M, N;
    while (cin >> M >> N) {
        vector<vector<int> > matrix(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        int sum = 0, minSum = INT_MAX;
        dfs(matrix, 0, 0, sum, minSum);
        if (minSum == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << minSum << endl;
        }
    }
    return 0;
}
