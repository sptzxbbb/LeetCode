#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int a, int b) {
        long sign = (a * b < 0 ? -1 : 1);
        long numerator = abs((long)a);
        long denominator = abs((long)b);
        long integer = numerator / denominator;
        long remainder = numerator % denominator;
        vector<long> digit;
        multimap<long, pair<long, long> > t;
        bool repeat = false;
        long index = 0;
        while (remainder != 0) {
            remainder *= 10;
            long temp = remainder / denominator;
            remainder %= denominator;
            auto ret = t.equal_range(temp);
            for (auto it = ret.first; it != ret.second; ++it) {
                if (it->second.first == remainder) {
                    repeat = true;
                    index = it->second.second;
                    break;
                }
            }
            // repeat found
            if (repeat) {
                break;
            } else {
                // repeat not found
                digit.push_back(temp);
                pair<long, long> ele(remainder, digit.size() - 1);
                t.insert( pair<long, pair<long, long>> (temp, ele));
            }
        }
        string res;
        if (sign == -1) {
            res = '-';
        }
        res += helper(integer);
        if (digit.size()) {
            res += '.';
            for (int i = 0; i < (int)digit.size(); ++i) {
                if (repeat && index == i) {
                    res += '(';
                }
                res += helper(digit[i]);
            }
            if (repeat) {
                res += ')';
            }
        }
        return res;
    }
    string helper(long k) {
        char buf[32];
        sprintf(buf, "%ld", k);
        string s = buf;
        return s;
    }
};

int main(int argc, char *argv[])
{
    long a = -1;
    long b = -INT_MIN;
    Solution k;
    cout << k.fractionToDecimal(a, b) << endl;
    return 0;
}
