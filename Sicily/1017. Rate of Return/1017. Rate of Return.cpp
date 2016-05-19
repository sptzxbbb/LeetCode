#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    int N, turn = 1;
    while (cin >> N && N != -1) {
        vector<int> month(N);
        vector<double> money(N);
        for (int i = 0; i < N; i++) {
            cin >> month[i] >> money[i];
        }
        int lastMonth;
        double targetMoney;
        cin >> lastMonth >> targetMoney;
        double rate = 2, low = 1, mid;
        while (rate - low >= 1e-6) {
            mid = (rate + low) / 2;
            double sum = 0;
            for (int i = 0; i < N; i++) {
                sum += money[i] * pow(mid, lastMonth - month[i] + 1);
            }
            if (sum < targetMoney) {
                low = mid;
            } else {
                rate = mid;
            }
        }
        if (turn != 1) {
            cout << endl;
        }
        cout << "Case " << turn++ << ": " << fixed << setprecision(5) << rate - 1 << endl;
    }
    return 0;
}
