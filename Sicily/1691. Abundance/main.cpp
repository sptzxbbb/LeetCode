// soj: 1691. Abundance
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int sigma(int n);

int main(int argc, char *argv[]) {
  int n, temp;
  cin >> n;
  while (n--) {
    int a, b, max = -1;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
      temp = sigma(i);
      if (max < temp) max = temp;
    }
    cout << max << endl;
  }
  return 0;
}


int sigma(int n) {
  int ans = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (i * i != n) ans += i + n / i;
      else ans += i;
    }
  }
  ans = ans - 2 * n;
  if (ans <= 0) ans = -1;
  return ans;
}

// sigma(12) = 1 + 2 + 3 + 4 + 6 + 12 =
// sqrt(12) = 3.XXX
// sigma(16) = 1 + 2 + 4 + 8 + 16
