#include "iostream"
#include "string"
#include "cmath"
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      ans += (s[s.size() - 1 - i] - 'A' + 1) * (int)(pow(26, i));
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution k;
  cout << k.titleToNumber("AAA") << endl;
  cout << (pow(26, 0)) << endl;
  return 0;
}
