#include "string"
#include "iostream"
using namespace std;


class Solution {
public:
  string addBinary(string a, string b) {
    // align two strings to make them of same size
    int diff = a.size() - b.size();
    if (a.size() > b.size()) {
      for (int i = 0; i < diff; ++i) {
        b = '0' + b;
      }
    } else {
      for (int i = 0; i < -diff; ++i) {
        a = '0' + a;
      }
    }
    // addition
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
      a[i] = (a[i] - '0') + b[i] + carry;
      carry = 0;
      if (a[i] > '1') {
        carry = 1;
        a[i] -= 2;
      }
    }
    // process the last carry 
    if (carry) a = '1' + a;
    return a;
  }
};

int main(int argc, char *argv[]) {
  string s1 = "1111", s2 = "111";
  Solution k;
  cout << k.addBinary(s1, s2) << endl;
  return 0;
}
