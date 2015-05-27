// soj: 1342. 开心的金明
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int main(int argc, char *argv[]) {
  int N, m;
  while (cin >> N >> m) {
    int price[m + 1], value[m + 1], significance, budge[N + 1];
    memset(budge, 0, sizeof(budge));
    
    for (int i = 1; i <= m; ++i) {
      cin >> price[i] >> significance;
      value[i] = price[i] * significance;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = N; j >= price[i]; --j) {
	budge[j] = max(budge[j], budge[j - price[i]] + value[i]);
      }
    }
    cout << budge[N] << endl;
  }
  return 0;
}
