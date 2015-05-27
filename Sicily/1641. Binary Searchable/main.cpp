// soj: 1641. Binary Searchable
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    int arr[n], count = 0;
    bool bin;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
      bin = true;
      for (int j = 0; j < i; ++j) {
	if (arr[j] > arr[i]) {
	  bin = false;
	  break;
	}
      }
      if (false == bin) continue;
      for (int k = i + 1; k != n; ++k) {
	if (arr[k] < arr[i]) {
	  bin = false;
	  break;
	}
      }
      if (bin) ++count;
    }
    cout << count << endl;
  }
  return 0;
}
