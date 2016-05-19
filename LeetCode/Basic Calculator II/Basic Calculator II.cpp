#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }
        int index = 0;
        deque<int> Operand;
        deque<char> Operator;
        while (index < size) {
            if (s[index] == ' ') {
                ++index;
            } else if (s[index] >= '0' && s[index] <= '9') {
                int num = 0;
                while (index < size && s[index] >= '0' && s[index] <= '9') {
                    num = num * 10 + s[index] - '0';
                    ++index;
                }
                Operand.push_back(num);
                if (!Operator.empty() &&
                    (Operator.back() == '*' || Operator.back() == '/')) {
                    char ch = Operator.back();
                    Operator.pop_back();
                    int num1, num2, res;
                    num1 = Operand.back();
                    Operand.pop_back();
                    num2 = Operand.back();
                    Operand.pop_back();
                    if (ch == '*') {
                        res = num1 * num2;
                    } else {
                        res = num2 / num1;
                    }
                    Operand.push_back(res);
                }
            } else {
                Operator.push_back(s[index++]);
            }
        }
        while (!Operator.empty()) {
            char ch = Operator.front();
            Operator.pop_front();
            int num1, num2, res;
            num1 = Operand.front();
            Operand.pop_front();
            num2 = Operand.front();
            Operand.pop_front();
            if (ch == '+') {
                res = num1 + num2;
            } else {
                res = num1 - num2;
            }
            Operand.push_front(res);
        }
        return Operand.front();
    }
};


int main(int argc, char *argv[])
{
    Solution k;
    cout << k.calculate("1-1 + 1") << endl;
    return 0;
}
