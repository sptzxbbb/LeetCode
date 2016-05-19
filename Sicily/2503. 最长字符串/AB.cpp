#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int numA, int numB, int maxA, int maxB, char cur, int same, int length, int& maxLength) {
    maxLength = max(maxLength, length);
    if (cur == 'A') {
        if (same < maxA && numA > 0) {
            dfs(numA - 1, numB, maxA, maxB, 'A', same + 1, length + 1, maxLength);
        }
        if (maxB >= 1 && numB > 0) {
            dfs(numA, numB - 1, maxA, maxB, 'B', 1, length + 1, maxLength);
        }
    }
    if (cur == 'B') {
        if (maxA >= 1 && numA > 0) {
            dfs(numA - 1, numB, maxA, maxB, 'A', 1, length + 1, maxLength);
        }
        if (same < maxB && numB > 0) {
            dfs(numA, numB - 1, maxA, maxB, 'B', same + 1, length + 1, maxLength);
        }
    }
}

int main(int argc, char *argv[]) {
    int numA, numB, maxA,maxB;
    cin >> numA >> numB >> maxA >> maxB;
    int maxLength = 0;
    dfs(numA, numB, maxA, maxB, 'A', 0, 0, maxLength);
    cout << maxLength << endl;
    return 0;
}
