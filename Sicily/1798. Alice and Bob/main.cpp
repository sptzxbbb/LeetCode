// soj: 1798. Alice and Bob
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n) {
    if (n % 2 == 0) cout << "Alice" << endl;
    if (n % 2 == 1) cout << "Bob" << endl;
    cin >> n;
  }
  return 0;
}



