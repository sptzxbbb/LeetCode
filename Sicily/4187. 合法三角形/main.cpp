// soj: 4187. 合法三角形
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    if (num[0] + num[1] > num[2]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
