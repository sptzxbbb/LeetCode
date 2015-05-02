// soj: 3496. 鸡兔同笼
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int m, n;
  cin >> m >> n;
  while (m != 0) {
    int x, y;
    y = (n - 2 * m) / 2;
    x = m - y;
    if (x > 0 && y > 0) {
      cout << x << ' ' << y << endl;
    } else {
      cout << "No answer" << endl;
    }
    cin >> m >> n;
  }

  return 0;
}




// x + y = m;  ->  2x + 2y = 2m
// 2x + 2y = 2m;    A
// 2x + 4y = n;     B
// B - A
// 2y = n - 2m;
// y = (n - 2m) / 2;
// x = m - y;

