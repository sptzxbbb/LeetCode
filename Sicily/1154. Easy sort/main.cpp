// soj: 1154. Easy sort
// Sat Nov 29, 2014--------Shawn Chow

#include "algorithm"
#include "iostream"
using namespace std;

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
    sort(arr, arr + m);
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << endl;
    }
  }
  return 0;
}

