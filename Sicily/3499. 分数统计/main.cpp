// soj: 3499. 分数统计
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; ++i) {
      cin >> arr[i];
    }
    
    sort(arr, arr + m);
    double ave = 0;
    for (int i = 1; i < m - 1; ++i) {
      ave += arr[i];
    }
    ave /= m - 2;

    cout.precision(2);
    cout << fixed << ave << endl;
  }
  return 0;
}


