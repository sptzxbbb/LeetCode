// soj: 4188. 进制转换
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "stack"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, temp;
    cin >> n;
    stack<int> bin;
    do {
      bin.push(n % 2);
      n /= 2;
    } while (n);

    while (!bin.empty()) {
      cout << bin.top();
      bin.pop();
    }
    cout << endl;
  }
  return 0;
}
