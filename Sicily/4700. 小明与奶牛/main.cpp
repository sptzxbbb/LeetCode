// soj: 4700. 小明与奶牛
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int number, product, max1 = -1, max2 = -1, max3 = -1;
    for (int i = 0; i < n; ++i) {
      cin >> number >> product;
      if (1 == number && product > max1) max1 = product;
      if (2 == number && product > max2) max2 = product;
      if (3 == number && product > max3) max3 = product;
    }
    if (max1 > 0) cout << 1 << ' ' << max1 << endl;
    if (max2 > 0) cout << 2 << ' ' << max2 << endl;
    if (max3 > 0) cout << 3 << ' ' << max3 << endl;
  }
  return 0;
}
