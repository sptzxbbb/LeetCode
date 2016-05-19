#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    while (N--) {
        int G;
        cin >> G;
        vector<int> v(G);
        for (int i = 0; i < G; i++) {
            cin >> v[i];
        }
        bool same = true;
        int m = G;
        while (true) {
            set<int> modulo;
            same = false;
            for (int i = 0; i < G; i++) {
                if (modulo.count(v[i] % m)) {
                    same = true;
                    break;
                } else {
                    modulo.insert(v[i] % m);
                }
            }
            if (same) {
                ++m;
            } else {
                break;
            }
        }
        cout << m << endl;
    }
    return 0;
}
