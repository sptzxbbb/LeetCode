// soj: 1306. Sorting Algorithm
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  while (n != 0) {
    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);

    cout << arr[0];
    for (int i = m; i < n; i += m) {
      cout << ' ' << arr[i];
    }
    cout << endl;
    cin >> n >> m;
  }
  return 0;
}

