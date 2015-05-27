// soj: 1020. Big Integer
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int mod(string s, int m) {
  int n = 0;
  for (int i = 0; i < s.size(); ++i) {
    n = 10 * n + s[i] - '0';
    n %= m;
  }
  return n;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; ++i) {
      cin >> arr[i];
    }
    string VLI;
    cin >> VLI;
    cout << '(';
    for (int i = 0; i < m - 1; ++i) {
      cout << mod(VLI, arr[i]) << ',';
    }
    cout << mod(VLI, arr[m - 1]) << ')' << endl;
  }
  return 0;
}
