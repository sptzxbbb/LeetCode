// soj: 1636. show me the money
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int money, m, price, num;
    cin >> money >> m;
    for (int i = 0; i < m; ++i) {
      cin >> price >> num;
      money -= price * num;
    }
    if (money >= 0) cout << money << endl;
    else cout << "Not enough" << endl;
  }
  return 0;
}
