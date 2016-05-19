// soj: 1371. Fireworks Show
// Thu Dec 11, 2014--------Shawn Chowj
#include "iostream"
#include "cstring"
using namespace std;

int main(int argc, char *argv[]) {
  int C, N, ans = 0;
  cin >> C >> N;
  bool show[N + 1];
  memset(show, false, sizeof(show));
  while (C--) {
    int interval, time;
    cin >> interval;
    time = interval;
    while (time <= N) {
      show[time] = true;
      time += interval;
    }
  }
  for (int i = 1; i <= N; ++i) {
    if (show[i]) ++ans;
  }
  cout << ans << endl;
  return 0;
}


