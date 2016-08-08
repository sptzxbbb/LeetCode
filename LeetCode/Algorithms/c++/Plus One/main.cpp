#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      digits[i] += carry;
      carry = digits[i] / 10;
      digits[i] %= 10;
    }
    // final carry
    if (carry) {
      vector<int>::iterator it = digits.begin();
      digits.insert(it, 1);
    }
    return digits;
  }
};

int main(int argc, char *argv[]) {
  vector<int> a;
  for (int i = 8; i >= 0; --i) {
    a.push_back(9);
  }
  Solution ans;
  ans.plusOne(a);
  for (int i = 0; i < 10; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
