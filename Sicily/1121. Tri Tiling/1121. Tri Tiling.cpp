#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 31;
vector<int> table(SIZE, 0);

int num(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }
    if (table[n] != 0) {
        return table[n];
    }
    int sum = 0;
    sum += 3 * num(n - 2);
    int count = n - 4;
    while (count >= 0) {
        sum += 2 * num(count);
        count -= 2;
    }
    table[n] = sum;
    return sum;
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n && n != -1) {
        if (n % 2 == 0) {
            cout << num(n) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}