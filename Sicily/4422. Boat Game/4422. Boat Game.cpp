#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int numCase;
    cin >> numCase;
    while (numCase--) {
        int n, m, apple;
        cin >> n >> m >> apple;
        int pos = 1, distance = 0, col;
        while (apple--) {
            cin >> col;
            if (col < pos) {
                distance += pos - col;
                pos = col;
            } else if (col > (pos + m - 1)) {
                distance += col - (pos + m - 1);
                pos += col - (pos + m - 1);
            }
        }
        cout << distance << endl;
    }
    return 0;
}
