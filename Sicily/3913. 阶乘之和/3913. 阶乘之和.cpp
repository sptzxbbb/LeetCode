#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int sum = 0, mask = 1000000, n, cur = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cur = cur * i % mask;
        sum = (sum + cur) % mask;
    }
    cout << sum << endl;
    return 0;
}
