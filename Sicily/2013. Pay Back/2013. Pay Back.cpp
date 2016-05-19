#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    int step = 0, balance = 0, debt = 0, money, pos = -1;
    for (int i = 0; i < N; i++) {
        ++step;
        cin >> money;
        if (money > 0) {
            balance += money;
            if (pos != -1 && balance >= debt) {
                balance -= debt;
                debt = 0;
                step += (i - pos) * 2;
                pos = -1;
            }
        } else {
            if (balance >= abs(money)) {
                balance += money;
            } else {
                debt += abs(money);
                if (pos == -1) {
                    pos = i;
                }
            }
        }
    }
    cout << step << endl;
    return 0;
}
