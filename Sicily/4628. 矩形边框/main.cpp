// soj: 4628. 矩形边框
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int w, h;
    cin >> w >> h;
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
	if (1 == i || h == i) {
	  cout << '*';
	} else {
	  if (1 == j || w == j) cout << '*';
	  else cout << ' ';
	}
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
