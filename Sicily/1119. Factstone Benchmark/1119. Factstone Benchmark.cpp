#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
    int year;
    while (cin >> year && year != 0) {
        int upperBound = (int)pow(2, (year - 1960) / 10 + 2);
        int n = 0;
        double sum = 0;
        while (sum <= upperBound) {
            ++n;
            sum += log(n) / log(2);
        }
        --n;
        cout << n << endl;
    }
    return 0;
}
