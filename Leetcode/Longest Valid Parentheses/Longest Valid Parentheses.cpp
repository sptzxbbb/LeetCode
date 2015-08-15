#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, char>> stk;
        int maxLen = 0, curLen = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                stk.push(make_pair(i, '('));
            } else {
                if (stk.empty() || stk.top().second == ')') {
                    stk.push(make_pair(i, ')'));
                } else {
                    stk.pop();
                    curLen = stk.empty() ? i + 1 : i - stk.top().first;
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


















