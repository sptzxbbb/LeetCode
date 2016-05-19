// soj: 4186. Matrix Addition
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int A[11][11], B[11][11], C[11][11];

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n != 0) {

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
	cin >> A[i][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
	cin >> B[i][j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
	C[i][j] = A[i][j] + B[i][j];
	cout << C[i][j];
	if (j != n) cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
