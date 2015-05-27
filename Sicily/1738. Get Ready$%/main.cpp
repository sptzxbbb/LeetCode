// soj: 1738. Get Ready?
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

struct team {
  int ID;
  int score;
};


bool cmp(team a, team b) {
  if (a.score > b.score) return true;
  else return false;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n;
    team k[n];
    for (int i = 0; i < n; ++i) {
      cin >> k[i].ID >> k[i].score >> p;
    }
    sort(k, k + n, cmp);
    cout << k[0].ID;
    for (int i = 1; i < n; ++i) {
      cout << ' ' << k[i].ID;
    }
    cout << endl;
  }
  return 0;
}
