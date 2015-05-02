//  1002. Anti-prime Sequences--------Shawn Chow
//  Thu Nov 27, 2014
#include "iostream"
#include "cstring"
using namespace std;

bool antiprime(int pos, int value);
bool prime(int a);
void traceback(int pos);

bool ans;
int m, n, d;
int vis[1001], arr[1001];

int main(int argc, char *argv[]) {
  while (cin >> n >> m >> d && n) {
    ans = false;
    memset(vis, 0, sizeof(vis));
    traceback(0);

    if (ans) {
      for (int i = 0; i < m-n; ++i) {
        cout << arr[i] << ",";
      }
      cout << arr[m - n] << endl;
    } else {
      cout << "No anti-prime sequence exists." << endl;
    }
  }
  return 0;
}

bool prime(int a) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}

bool antiprime(int pos, int value) {
  int t = d;
  t--;
  --pos;
  while (t-- && pos >= 0) {
    value += arr[pos];
    --pos;
    if (prime(value)) return false;
  }
  return true;
}

void traceback(int pos) {
  for (int i = n; i <= m; ++i) {
    if (vis[i] == 0 && antiprime(pos, i)) {
      vis[i] = 1;
      arr[pos] = i;
      if (pos == m - n) {
	ans = 1;
	return;
      }
      traceback(pos + 1);
      if (1 == ans) return;
      vis[i] = 0;
    }
  }
}
