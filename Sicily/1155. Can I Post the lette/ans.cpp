// Problem#: 1155
// Submission#: 3915012
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& next, vector<bool>& visit, int cur, bool& ans) {
    if (cur == (int)next.size() - 1) {
        ans = true;
        return;
    }
    for (int i = 0; i < (int)next[cur].size(); i++) {
        int index = next[cur][i];
        if (!visit[index]) {
            visit[index] = true;
            dfs(next, visit, index, ans);
            if (ans) {
                break;
            }
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int N, M;
    while (cin >> N, N != 0) {
        cin >> M;
        int from, to;
        vector<vector<int> > next(N);
        vector<bool> visit(N, false);
        for (int i = 0; i < M; i++) {
            cin >> from >> to;
            next[from].push_back(to);
        }
        bool ans = false;
        dfs(next, visit, 0, ans);
        if (ans) {
            cout << "I can post the letter" << endl;
        } else {
            cout << "I can't post the letter" << endl;
        }
    }
    return 0;
}