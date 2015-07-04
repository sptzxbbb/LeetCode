#include "iostream"
#include "stack"
#include "string"
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> parent;
    for (int i = 0; i < s.size(); ++i) {
      if ('{' == s[i] || '[' == s[i] || '(' == s[i])
        parent.push(s[i]);
      else if (!parent.empty() && (
           ('}' == s[i] && '{' == parent.top()) ||
           (']' == s[i] && '[' == parent.top()) ||
           (')' == s[i] && '(' == parent.top())
                                   )) {
        parent.pop();
      } else {
        return false;
      }
    }
    if (parent.empty()) return true;
    else return false;
  }
};
