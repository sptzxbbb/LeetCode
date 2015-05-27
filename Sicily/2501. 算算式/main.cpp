// soj: 2501. 算算式
// Thu Dec 18, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
  int n, k, ans, s;
  cin >> n >> k;
  s = 1;
  for (int i = 0; i < k; ++i) {
    s *= n;
    s %= 9901;
  }
  ans = (n * (s - 1) / (n - 1)) % 9901;
  cout << ans << endl;
    return 0;
}
