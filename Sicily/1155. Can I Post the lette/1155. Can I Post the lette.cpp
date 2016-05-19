#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<bool>& visit, vector<vector<bool> >& connect) {
    visit[cur] = true;
    for (int i = 0; i < (int)visit.size(); i++) {
        if (!visit[i] && connect[cur][i]) {
            dfs(i, visit, connect);
        }
    }
}

int main(int argc, char *argv[]) {
    int N, M;
    while (cin >> N, N != 0) {
        cin >> M;
        int from, to;
        vector<vector<bool> > connect(N, vector<bool>(N, false));
        vector<bool> visit(N, false);
        for (int i = 0; i < M; i++) {
            cin >> from >> to;
            connect[from][to] = true;
        }
        dfs(0, visit, connect);
        if (visit[N - 1]) {
            cout << "I can post the letter" << endl;
        } else {
            cout << "I can't post the letter" << endl;
        }
    }
    return 0;
}
