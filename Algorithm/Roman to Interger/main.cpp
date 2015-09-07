#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      // left < right
      if (i < s.size() - 1 && romanNum(s[i]) < romanNum(s[i + 1])) {
        ans -= romanNum(s[i]);
      } else {
        ans += romanNum(s[i]);
      }
    }
    return ans;
  }
 
  int romanNum(int a) {
    switch (a) {
    case 'I' : return 1;
    case 'V' : return 5;
    case 'X' : return 10;
    case 'L' : return 50;
    case 'C' : return 100;
    case 'D' : return 500;
    case 'M' : return 1000;
    }
  }
};
// MCDLXXVI == 1476
int main(int argc, char *argv[]) {
  Solution a;
  string s = "MMMCCCXXXIII";
  cout << a.romanToInt(s) << endl;
  return 0;
}
