// soj: 1294. 高级机密
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = 1;
  for (int i = 0; i < b; ++i) {
    ans = (ans * a) % c;
  }
  cout << ans << endl;
  return 0;
}



// a = n * b + k;
// k = a mod b
// a * a = (n*b+k)*(n*b+k) = (nb)^2 + k^2 + 2knb
// a * a mod b = k^2 mod b;
// a * a * a *~~~~~~* a= (b1 + b2 + b3 +~~~~~+ k^n)
// ans = k^n mod b

