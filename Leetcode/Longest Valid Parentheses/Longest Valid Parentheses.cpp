#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size(), ans = 0, length = 0;
        stack<char> unmatch;
        for (int i = 0; i < size; i++) {
            if (')' == s[i] && !unmatch.empty() &&'(' == unmatch.top()) {
                unmatch.pop();
                length += 2;
                ans = max(ans, length);
            } else {
                if (')' == s[i] || (!unmatch.empty() && '(' == unmatch.top() )) {
                    length = 0;
                }
                unmatch.push(s[i]);
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution k;
    string s = "()()";
    k.longestValidParentheses(s);
    return 0;
}


















