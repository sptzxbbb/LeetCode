#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int integer = numerator / denominator;
        int remainder = numerator % denominator;
        vector<int> digit;
        map<int, int> t;
        bool repeat = false;
        int index = 0;
        while (remainder != 0) {
            remainder *= 10;
            int temp = remainder / denominator;
            // repeat found
            if (t.find(temp) != t.end()) {
                repeat = true;
                index = t[temp];
                break;
            } else {
                digit.push_back(temp);
                t[temp] = digit.size() - 1;
            }
            remainder = remainder % denominator;
        }
        string res;
        res = helper(integer);
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
    string helper(int k) {
        char buf[32];
        sprintf(buf, "%d", k);
        string s = buf;
        return s;
    }
};

int main(int argc, char *argv[])
{
    int a = 1;
    int b = 6;
    Solution k;
    cout << k.fractionToDecimal(a, b) << endl;
    return 0;
}
