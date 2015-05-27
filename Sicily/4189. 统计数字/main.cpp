// soj: 4189. 统计数字
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "set"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n != 0) {
    string s;
    set<string> num;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      num.insert(s);
    }
    cout << num.size() << endl;
  }
  return 0;
}
