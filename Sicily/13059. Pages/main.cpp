// soj: 13059. Pages
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    if (0 == n) break;
    int arr[21], count = 1;
    arr[0] = n;
    for (int i = 1; cin >> n, n != 0; ++i) {
      arr[i] = n;
      ++count;
    }

    bool condense = false;
    for (int i = 0; i < count - 1; ++i) {
      if (!condense && arr[i] + 1 == arr[i + 1]) {
        cout << arr[i] << '-';
        condense = true;
      } else if (condense && arr[i] + 1 != arr[i + 1]) {
        cout << arr[i] << ',';
        condense = false;
      } else if (!condense && arr[i] + 1 != arr[i + 1]) {
        cout << arr[i] << ',';
      }
    }
    if (condense && arr[count - 1] == (arr[count - 2] + 1)) cout << arr[count - 1] << endl;
    else if (condense && arr[count - 1] != (arr[count - 2] + 1)) cout << ',' << arr[count - 1] << endl;
    else if (!condense) cout << arr[count - 1] << endl;
  }
  return 0;
}
