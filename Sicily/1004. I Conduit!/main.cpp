// soj: 1004. I Conduit!
// Sun Dec 28, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

const double MAX = 99999999;
const double EPS = 1e-7;

int cmp(double x1, double x2) {
  if (x1 - x2 < -EPS) return -1;
  if (x1 - x2 > EPS) return 1;
  return 0;
}

struct segment {
  double start, end;
  double k, b;
  segment(double X1 = 0, double Y1 = 0, double X2 = 0, double Y2 = 0) {
    if (cmp(X1, X2) == 0) {
      k = MAX;
      b = X1;
      start = min(Y1, Y2);
      end = max(Y1, Y2);
    } else {
      k = (Y2 - Y1) / (X2 - X1);
      b = Y1 - k * X1;
      start = min(X1, X2);
      end = max(X1, X2);
    }
  }
};

bool cmpline(segment a, segment b) {
  if (cmp(a.k, b.k)) return cmp(a.k, b.k) < 0;
  if (cmp(a.b, b.b)) return cmp(a.b, b.b) < 0;
  return cmp(a.start, b.start) < 0;
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n) {
    int ans = n;
    segment line[n];
    double x1, x2, y1, y2;
    for (int i = 0; i < n; ++i) {
      cin >> x1 >> y1 >> x2 >> y2;
      line[i] = segment(x1, y1, x2, y2);
    }

    sort(line, line + n, cmpline);

    double maxEnd = line[0].end;
    for (int i = 1; i < n; ++i) {
      if (cmp(line[i].k, line[i - 1].k) == 0 && cmp(line[i].b, line[i - 1].b) == 0) {
        if (cmp(line[i].start, maxEnd) <= 0) --ans;
        maxEnd = max(maxEnd, line[i].end);
      } else {
        maxEnd = line[i].end;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
