// soj: 1295. 负权数
// Sun Dec 7, 2014--------Shawn Chow
#include "iostream"
#include "stack"
using namespace std;

int main(int argc, char *argv[]) {
  int n, R, x;
  char digit[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  while (cin >> n) {
    cin >> R;
    stack<char> m;
    if (0 == n) {
      cout << '0' << endl;
      continue;
    }
    while (n) {
      x = n % R;
      if (n > 0 || 0 == x) {
	n = n / R;
      } else {
	n = n / R + 1;
	x -= R;
      }
      m.push(digit[x]);
    }

    while (!m.empty()) {
      cout << m.top();
      m.pop();
    }
    cout << endl;
  }
  return 0;
}
