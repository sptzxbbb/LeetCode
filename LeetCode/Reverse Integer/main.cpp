#include "iostream"
#include "string"
#include "limits.h"
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0, digit;
    long long max = 0;
    while (x) {
      digit = x % 10;
      max = max * 10 + digit;
      if (max > INT_MAX || max < INT_MIN) {
        return 0;
      }
      ans = ans * 10 + digit;
      x /= 10;
    }
    if (x < 0) ans = -ans;
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution a;
  cout << a.reverse(-2147483648) << endl;
  cout << INT_MAX << endl;
  return 0;
}
