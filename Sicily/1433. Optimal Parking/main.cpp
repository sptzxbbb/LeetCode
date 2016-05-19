//  1433. Optimal Parking--------Shawn Chow
//  Thu Nov 27, 2014
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, min = 100, max = -1;
    cin >> m;
    while (m--) {
      int pos;
      cin >> pos;
      if (pos > max) max = pos;
      if (pos < min) min = pos;
    }
    cout << 2 * (max - min) << endl;
  }
  return 0;
}                                 
