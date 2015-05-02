// soj: 1157. The hardest problem
// Sat Nov 29, 2014--------Shawn Chow

#include "iostream"
using namespace std;

const int Min = -65536;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n) {
    int temp, ans = Min;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      if (ans < temp) ans = temp;
    }
    cout << ans << endl;
    cin >> n;
  }
  return 0;
}
