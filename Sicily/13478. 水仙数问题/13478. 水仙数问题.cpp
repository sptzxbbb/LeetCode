#include <iostream>
#include <cmath>
using namespace std;

bool isNarci(int n) {
    int sum = 0, temp = n;
    while (temp != 0) {
        sum += pow((temp % 10), 3);
        temp /= 10;
    }
    if (sum == n) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 100; i <= n; i++) {
        if (isNarci(i)) {
            cout << i << endl;
        }
    }
    return 0;
}
