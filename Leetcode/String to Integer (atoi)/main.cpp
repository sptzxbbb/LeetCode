#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        // empty string
        if (!size) {
            return 0;
        }
        int index = 0;
        // discard whitespace
        while (index <= size && ' ' == str[index]) {
            ++index;
        }
        // str contains only whitespace
        if (index > size) {
            return 0;
        }
        char sign = '+';
        if ('-' == str[index]) {
            sign = '-';
            ++index;
        } else if ('+' == str[index]) {
            ++index;
        }
        long num = 0, max = INT_MAX, min = -(long)INT_MIN;
        bool overflow = false;
        while (index <= size) {
            if (str[index] >= '0' && str[index] <= '9') {
                num = num * 10 + (str[index] - '0');
                if (('+' == sign && num > max) ||
                    ('-' == sign && num > min)) {
                    overflow = true;
                    break;
                }
            } else {
                break;
            }
            ++index;
        }
        if (!overflow) {
            if ('-' == sign) return -num;
            else return num;
        } else {
            if ('-'== sign) return INT_MIN;
            else return INT_MAX;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    string s = "-1";
    cout << k.myAtoi(s) << endl;

    return 0;
}

