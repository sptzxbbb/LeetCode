// soj: 1438. Shopaholic
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 3 == 0) sum += arr[n - i];
    }
    cout << sum << endl;
  }
  return 0;
}
