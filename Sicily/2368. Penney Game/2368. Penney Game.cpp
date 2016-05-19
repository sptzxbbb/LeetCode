#include <iostream>
#include <vector>
using namespace std;
const int times = 40;

int main(int argc, char *argv[]) {
    int P;
    cin >> P;
    while (P--) {
        int num;
        cin >> num;
        vector<int> comb(8, 0);
        vector<char> sequence(times);
        for (int i = 0; i < times; i++) {
            cin >> sequence[i];
            if (i >= 2) {
                if (sequence[i - 2] == 'T' && sequence[i - 1] == 'T' && sequence[i] == 'T') {
                    ++comb[0];
                } else if (sequence[i - 2] == 'T' && sequence[i - 1] == 'T' && sequence[i] == 'H') {
                    ++comb[1];
                } else if (sequence[i - 2] == 'T' && sequence[i - 1] == 'H' && sequence[i] == 'T') {
                    ++comb[2];
                } else if (sequence[i - 2] == 'T' && sequence[i - 1] == 'H' && sequence[i] == 'H') {
                    ++comb[3];
                } else if (sequence[i - 2] == 'H' && sequence[i - 1] == 'T' && sequence[i] == 'T') {
                    ++comb[4];
                } else if (sequence[i - 2] == 'H' && sequence[i - 1] == 'T' && sequence[i] == 'H') {
                    ++comb[5];
                } else if (sequence[i - 2] == 'H' && sequence[i - 1] == 'H' && sequence[i] == 'T') {
                    ++comb[6];
                } else if (sequence[i - 2] == 'H' && sequence[i - 1] == 'H' && sequence[i] == 'H') {
                    ++comb[7];
                }
            }
        }
        cout << num << ' ';
        for (int i = 0; i < 7; i++) {
            cout << comb[i] << ' ';
        }
        cout << comb[7] << endl;
    }
    return 0;
}
