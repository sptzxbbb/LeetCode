#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        string unit[4] = {"", "Thousand", "Million", "Billion"};
        string res;
        for (int i = 0; i < 4; i++) {
            int temp = num % 1000;
            num /= 1000;
            if ((i == 0) || (i != 0 && temp != 0)) {
                if (res.size() > 0) {
                    res = " " + res;
                }
                res = helper(temp) + (i == 0 ? "" : " ") + unit[i] + res;
            }
        }
        if (res.size() > 4 && res.substr(res.size() - 4) == "Zero") {
            res = res.substr(0, res.size() - 5);
        }

        return res;
    }
    string helper(int num) {
        string one[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string ten1[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ten2[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string s;
        int hundred = num / 100;  // 1
        int tens = num / 10 % 10;  // 2
        int ones = num % 10;  // 3
        if (hundred != 0) {
            s += one[hundred] + " " + "Hundred";
        }
        if (tens != 0) {
            s += s.size() > 0 ? " " : "";
            if (tens == 1) {
                s += ten1[ones];
                return s;
            } else {
                s += ten2[tens - 2];
            }
        }
        if (ones != 0) {
            s += s.size() > 0 ? " " : "";
            s += one[ones];
        } else if (s.size() == 0) {
            s += one[ones];
        }
        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    int num = 1000;
    cout << k.numberToWords(num) << endl;
    return 0;
}
