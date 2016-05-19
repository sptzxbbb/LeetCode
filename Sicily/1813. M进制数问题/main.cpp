// soj: 1813. M进制数问题
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "stack"
using namespace std;

int dec(string a, int base) {
  int sum = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] >= '0' && a[i] <= '9') sum = sum * base + a[i] - '0';
    if (a[i] >= 'A' && a[i] <= 'Z') sum = sum * base + a[i] - 'A' + 10;
  }
  return sum;
}

string change(int num, int base) {
  string dig = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", ans = "";
  stack<char> s;
  do {
    s.push(dig[num % base]);
    num /= base;
  } while (num != 0);

  while (!s.empty()) {
    ans += s.top();
    s.pop();
  }

  return ans;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int base;
    cin >> base;
    string A, B;
    cin >> A >> B;
    int temp1 = dec(A, base), temp2 = dec(B, base), P, Q;
    P = temp1 / temp2;
    Q = temp1 % temp2;
    cout << change(P, base) << endl << change(Q, base) << endl;
  }
  return 0;
}
