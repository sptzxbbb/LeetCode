class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        int sum = 0;
        stack<int> s;
        for (int i = 0; i < size; i++) {
            string a = tokens[i];
            // operator
            if (a.size() == 1 && (a[0] > '9' || a[0] < '0')) {
                int op1, op2;
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                switch (a[0]) {
                    case '+' :
                        s.push(op1 + op2);
                        break;
                    case '-' :
                        s.push(op1 - op2);
                        break;
                    case '*' :
                        s.push(op1 * op2);
                        break;
                    case '/' :
                        s.push(op1 / op2);
                        break;
                    default :
                        // not reached
                        ;
                }
            } else {
                // operand
                s.push(atoi(a.c_str()));
            }
        }
        return s.top();
    }
};