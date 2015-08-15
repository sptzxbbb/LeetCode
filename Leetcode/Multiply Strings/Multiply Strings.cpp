#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            string s = "0";
            return s;
        }
        int size1 = num1.size(), size2 = num2.size();
        int len = size1 + size2;
        vector<int> digit(len, 0);
        for (int i = size1 - 1; i >= 0; i--) {
            for (int j = size2 - 1; j >= 0; j--) {
                digit[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for (int i = len - 1; i >= 0; i--) {
            digit[i] += carry;
            carry = digit[i] / 10;
            digit[i] %= 10;
        }
        string s;
        int i = 0;
        if (digit[0] == 0) {
            ++i;
        }
        for (; i < digit.size(); i++) {
            s.push_back('0' + digit[i]);
        }
        return s;
    }
};

int main(int argc, char *argv[])
{
    string a = "98", b = "9";
    Solution k;
    k.multiply(a, b);
    return 0;
}
