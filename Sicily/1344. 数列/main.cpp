// soj: 1344. 数列
// Wed Dec 10, 2014--------Shawn Chow

#include "iostream"
#include "list"
using namespace std;

int main(int argc, char *argv[]) {
  int k, N;
  while (cin >> k >> N) {
    int quo = N, t, ans = 0, weight = 1;
    list<int> bin;
    while (N != 0) {
      t = N % 2;
      N /= 2;
      bin.push_back(t);
    }

    while (!bin.empty()) {
      ans += bin.front() * weight;
      bin.pop_front();
      weight *= k;
    }
    cout << ans << endl;
  }
  return 0;
}

// 1 10  11  100  101  110   111
// 0 1  0+1   2   0+2  1+2   2+1+0


// 8 / 2 = 4..0
// 4 / 2 = 2..0
// 2 / 2 = 1..0
// 1 / 2 = 0..1
