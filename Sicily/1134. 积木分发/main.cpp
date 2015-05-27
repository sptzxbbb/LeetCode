// soj: 1134. 积木分发
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

struct node {
  int have;
  int need;
};

bool cmp(node kid1, node kid2);

int main(int argc, char *argv[]) {
  int n, s;
  while (1) {
    cin >> n;
    if (n == 0) break;
    cin >> s;

    node kid[n];
    for (int i = 0; i < n; ++i) {
      cin >> kid[i].have >> kid[i].need;
    }

    sort(kid, kid + n, cmp);

    bool all = true;
    for (int i = 0; i < n; ++i) {
      if (s >= kid[i].need) {
	s += kid[i].have;
      } else {
	all = false;
	break;
      }
    }

    if (all) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

bool cmp(node kid1, node kid2) {
  if (kid1.need < kid2.need) return true;
  return false;
}
