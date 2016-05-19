// soj: 1370. How many 0's?
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include <vector>
#include <cmath>
using namespace std;

const int size = 10;
// zero[i] : [K00..00, K99..99], 长度为i, 首位固定且不为0的所有数字的0的个数.
vector<int> zero(size + 1, 0);

void initial(void) {
    zero[1] = 0;
    zero[2] = 1;
    for (int i = 3; i < size; i++) {
        zero[i] = 10 * zero[i - 1] + (int)pow(10, i - 2);
    }
}

int numZero(int k) {
    int temp = k;
    vector<int> digit;
    if (k == 0) {
        digit.push_back(0);
    }
    while (temp != 0) {
        digit.push_back(temp % 10);
        temp /= 10;
    }
    int res = 0;
    res += 1;
    // [0, K000..000)
    int size = digit.size();
    for (int i = 1; i <= size - 1; i++) {
        res += 9 * zero[i];
    }
    res += (digit[size - 1] - 1) * zero[size];
    // [K000.000, KABC...DEF]
    for (int i = size - 2; i >= 0; i--) {
        if (digit[i] > 0) {
            res += (digit[i] * zero[i + 1] + (int)pow(10, i));
        } else {
            res += k % (int)pow(10, i) + 1;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    initial();
    int m, n;
    while (cin >> m >> n && m != -1) {
        cout << numZero(n) - numZero(m - 1) << endl;
    }
    return 0;
}
