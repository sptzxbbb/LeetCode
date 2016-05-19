#include <iostream>
#include <vector>
#include <string>
using namespace std;

string add(string a, string b) {
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    while (b.size() < a.size()) {
        b = "0" + b;
    }
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        a[i] += (b[i] - '0') + carry;
        carry = 0;
        if (a[i] > '9') {
            a[i] -= 10;
            carry = 1;
        }
    }
    if (carry) {
        a = '1' + a;
    }
    return a;
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n) {
        string s;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i > 0) {
                v[0] = add(v[0], v[i]);
            }
        }
        cout << v[0] << endl;
    }
    return 0;
}

// Sample Input
// 3 1 2 3
// 1 123
// 2 1111111111111111111111111111111111 1111111111111111111111111111111111
// Sample Output

// 6
// 123
// 2222222222222222222222222222222222