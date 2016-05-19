// soj: 1232. Electrical Outlets
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int k, sum = 1, strip;
    cin >> k;
    for (int i = 0; i < k; ++i) {
      cin >> strip;
      sum += strip - 1;
    }
    cout << sum << endl;
  }

  return 0;
}
