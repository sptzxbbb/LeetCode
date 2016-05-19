#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dfs(vector<int>& s, int num, int pos, int& best, int target);

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    while (N--) {
        int target;
        vector<int> v(5);
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
        }
        cin >> target;
        int best = INT_MIN;
        dfs(v, 5, -1, best, target);
        cout << best << endl;
    }
    return 0;
}

void dfs(vector<int>& v, int num, int pos, int& best, int target) {
    for (int i = 0; i < num; i++) {
        if (v[i] <= target && v[i] > best) {
            best = v[i];
        }
    }
    if (num == 1 || best == target) {
        return;
    }
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            int op1 = v[i], op2 = v[j];
            swap(v[j], v[num - 1]);

            v[i] = op1 + op2;
            dfs(v, num - 1, i, best, target);

            v[i] = op1 - op2;
            dfs(v, num - 1, i, best, target);
            v[i] = op2 - op1;
            dfs(v, num - 1, i, best, target);

            v[i] = op1 * op2;
            dfs(v, num - 1, i, best, target);

            if (op1 != 0 && op2 % op1 == 0) {
                v[i] = op2 / op1;
                dfs(v, num - 1, i, best, target);
            }
            if (op2 != 0 && op1 % op2 == 0) {
                v[i] = op1 / op2;
                dfs(v, num - 1, i, best, target);
            }

            v[i] = op1;
            swap(v[j], v[num - 1]);
        }
    }
    return;
}
