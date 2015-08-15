#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, int>> stk;
        int maxLen = 0, curLen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(make_pair(i, '('));
            } else {
                // stk.top() == ')'
                if (stk.empty() || stk.top().second == ')') {
                    stk.push(make_pair(i, ')'));
                } else {
                    stk.pop();
                    if (stk.empty()) {
                        curLen = i + 1;
                    } else {
                        curLen = i - stk.top().first;
                    }
                    maxLen = max(maxLen, curLen);
                }

            }
        }
        return maxLen;
    }
};


int main(int argc, char *argv[]) {
    Solution k;
    string s = "()()";
    k.longestValidParentheses(s);
    return 0;
}


















