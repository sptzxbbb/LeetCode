// soj: 4312. A + B
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "list"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int a1, a2;
    cin >> a1 >> a2;
    list<int> A1, A2;
    do {
      A1.push_back(a1 % 10);
      a1 /= 10;
    } while (a1);
    
    do {
      A2.push_back(a2 % 10);
      a2 /= 10;
    } while (a2);

    int b1 = 0, b2 = 0;
    while (!A1.empty()) {
      b1 = b1 * 10 + A1.front();
      A1.pop_front();
    }

    while (!A2.empty()) {
      b2 = b2 * 10 + A2.front();
      A2.pop_front();
    }
    cout << b1 + b2 << endl;
  }
  return 0;
}
