// soj: 1052. Candy Sharing Game
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
using namespace std;

struct student {
  int candy;
  int left;
};

void gift(student* circle, int n) {
  for (int i = 0; i < n; ++i) {
    if (i != n - 1) {
      circle[i + 1].left = circle[i].candy / 2;
      circle[i].candy /= 2;
    } else {
      circle[0].left = circle[i].candy / 2;
      circle[i].candy /= 2;
    }
  }
}

void update(student* circle, int n) {
  for (int i = 0; i < n; ++i) {
    circle[i].candy += circle[i].left;
    circle[i].left = 0;
    if (circle[i].candy % 2 != 0) ++circle[i].candy;
  }
}

bool check(student* circle, int n) {
  int num = circle[0].candy;
  for (int i = 0; i < n; ++i) {
    if (circle[i].candy != num) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n != 0) {
    student circle[n];
    for (int i = 0; i < n; ++i) {
      cin >> circle[i].candy;
      circle[i].left = 0;
    }

    int ans = 0;
    while (!check(circle, n)) {
      gift(circle, n);
      update(circle, n);
      ++ans;
    }
    cout << ans << ' ' << circle[0].candy << endl;
    
  }
  return 0;
}
