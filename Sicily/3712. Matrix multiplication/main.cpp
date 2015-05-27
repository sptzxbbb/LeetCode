// soj: 3712. Matrix multiplication
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

int A[11][11], B[11][11], C[11][11];

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    memset(C, 0, sizeof(C));
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
	for (int k = 1; k <= n; ++k) {
	  C[i][j] += A[i][k] * B[k][j];
	}
	cout << C[i][j];
	if (j < n) cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}

