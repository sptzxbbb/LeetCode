#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m, value;
    cin >> n >> m;
    vector<int> hash(m, -1);
    for (int i = 0; i < n; i++) {
        cin >> value;
        int index = value % m;
        while (hash[index] != -1) {
            ++index;
            index %= m;
        }
        hash[index] = value;
    }
    for (int i = 0; i < m; i++) {
        cout << i << "#";
        if (hash[i] == -1) {
            cout << "NULL" << endl;
        } else {
            cout << hash[i] << endl;
        }
    }
    return 0;
}
