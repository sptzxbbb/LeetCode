#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dfs(vector<int>& v, int pos, int num, int sum, int& best, int target);

int main(int argc, char *argv[]) {
    int N, target;
    cin >> N >> target;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int best = INT_MIN;
    dfs(v, 0, 0, 0, best, target);
    cout << best << endl;
    return 0;
}

void dfs(vector<int>& v, int pos, int num, int sum, int& best, int target) {
    if (num == 3) {
        if (sum > best && sum <= target) {
            best = sum;
        }
        return;
    }
    for (int i = pos; i < (int)v.size(); i++) {
        dfs(v, i + 1, num + 1, sum + v[i], best, target);
    }
    return;
}




