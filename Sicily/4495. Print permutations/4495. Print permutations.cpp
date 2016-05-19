#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string str, vector<bool>& visit, int step, string cur) {
    if (step == (int)str.size()) {
        cout << cur << endl;
        return;
    }
    for (int i = 0; i < (int)str.size(); i++) {
        if (!visit[i]) {
            cur += str[i];
            visit[i] = true;
            permute(str, visit, step + 1, cur);
            visit[i] = false;
            cur.erase(cur.size() - 1, 1);
        }
    }
}

int main(int argc, char *argv[]) {
    string str;
    cin >> str;
    vector<bool> visit(str.size(), false);
    string cur = "";
    permute(str, visit, 0, cur);
    return 0;
}
