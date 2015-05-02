// soj: 11534. Strategy
// Sun Dec 28, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
  long long N1, N2, K, temp, pos = 2;
  cin >> N1 >> N2 >> K;
  if (1 == K) cout << N1 << endl;
  else if (2 == K) cout << N2 << endl;
  else {
    while (pos != K) {
      temp = abs(N2 - N1);
      N1 = N2;
      N2 = temp;
      ++pos;
    }
    cout << temp << endl;
  }
  return 0;
}
