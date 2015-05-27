// soj: 1146. 采药
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int main(int argc, char *argv[]) {
  int T, M;
  cin >> T >> M;
  int t[M + 1], v[M + 1];
  for (int i = 1; i <= M; ++i) {
    cin >> t[i] >> v[i];
  }

  int bag[T + 1];
  memset(bag, 0, sizeof(bag));
  for (int i = 1; i <= M; ++i) {
    for (int j = T; j >= t[i]; --j) {
      bag[j] = max(bag[j], bag[j - t[i]] + v[i]);
    }
  }

  cout << bag[T] << endl;
  return 0;
}
