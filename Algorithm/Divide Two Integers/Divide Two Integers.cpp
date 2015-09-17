#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        bool negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long _dividend = abs((long)dividend);
        long _divisor = abs((long)divisor);
        long weight = 0;
        int factor = 0, res = 0;

        while (_dividend >= _divisor) {
            weight = _divisor;
            factor = 1;
            while (weight + weight <= _dividend) {
                weight += weight;
                factor += factor;
            }
            _dividend -= weight;
            res += factor;
        }
        if (negative) {
            res = -res;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    cout << k.divide(INT_MIN, -1) << endl;
    cout << INT_MAX << endl;
    return 0;
}
