// soj: 3725. 陶陶考试
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n) {
    int max = -6553600, dif;
    for (int i = 0; i < n; ++i) {
      cin >> dif;
      if (dif > max) max = dif;
    }
    cout << max << endl;
    cin >> n;
  }
  return 0;
}
