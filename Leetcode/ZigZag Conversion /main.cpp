#include "iostream"
#include <string>
using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    string ans = "";
    int next;
    // first row
    if (1 == nRows) return s;
    for (int i = 0; i < s.size(); i += (nRows - 1) * 2) {
      ans += s[i];
    }
    // gap rows
    for (int i = 1; i < nRows - 1; ++i) {  // rows
      for (int j = i; j < s.size(); j+= (nRows - 1) * 2) {
        ans += s[j];
        next = j + (nRows - 1) * 2 - i * 2;
        if (next < s.size()) ans += s[next];
      }
    }
    // last row
    for (int i = (nRows - 1); i < s.size(); i += (nRows - 1) * 2) {
      ans += s[i];
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution a;
  string s = "ABCDEFGHIJKLMN";
  cout << a.convert(s, 4) << endl;
  return 0;
}
