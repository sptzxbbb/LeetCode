#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> operand;
        stack<char> sign;
        int index = 0, size = s.size();
        while (index < size) {
            if (s[index] == ' ') {
                ++index;
                continue;
            } else if (s[index] == '+' || s[index] == '-' || s[index] == '(') {
                sign.push(s[index++]);
            } else if (s[index] == ')') {
                helper(operand, sign);
                sign.pop();
                ++index;
            } else {
                int num = 0;
                while (index < size && s[index] >= '0' && s[index] <= '9') {
                    num = num * 10 + s[index++] - '0';
                }
                operand.push(num);
                helper(operand, sign);
            }
        }
        helper(operand, sign);
        return operand.top();
    }

    void helper(stack<int>& operand, stack<char>& sign) {
        while (!sign.empty() && sign.top() != '(') {
            int op1, op2;
            op1 = operand.top();
            operand.pop();
            op2 = operand.top();
            operand.pop();
            char c = sign.top();
            sign.pop();
            if (!sign.empty() && sign.top() == '-') {
                c = (c == '-' ? '+' : '-');
            }
            if (c == '+') {
                operand.push(op2 + op1);
            } else {
                operand.push(op2 - op1);
            }
        }
    }
};




int main(int argc, char *argv[])
{
    Solution k;
    string s = "(5-(1+(5)))";
    cout << k.calculate(s) << endl;
    return 0;
}
