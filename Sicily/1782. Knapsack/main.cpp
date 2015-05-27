// soj: 1782. Knapsack
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, volume;
    cin >> m >> volume;
    int c[m + 1], v[m + 1];
    memset(c, 0, sizeof(c));
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= m; ++i) {
      cin >> c[i];
      v[i] = c[i];
    }

    int bag[volume + 1];
    memset(bag, 0, sizeof(bag));
    for (int i = 1; i <= m; ++i) {
      for (int j = volume; j >= c[i]; --j) {
	bag[j] = max(bag[j], bag[j - c[i]] + v[i]);
      }
    }
    cout << bag[volume] << endl;
  }
  return 0;
}
