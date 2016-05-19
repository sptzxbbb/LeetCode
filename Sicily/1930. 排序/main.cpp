// soj: 1930. 排序
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n], cmp = 0, min, temp;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
      min = i;
      for (int j = i + 1; j < n; ++j) {
	if (arr[min] > arr[j]) {
	  cmp++;
	  min = j;
	}
      }
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
    cout << cmp << endl;
  }
  return 0;
}






// 4 1 3 2
// 1 2 3 4
