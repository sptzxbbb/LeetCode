// 1325. Digit Generator--------Shawn Chow
// Thu Nov 27, 2014

#include "iostream"
using namespace std;

int generator(int m);

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, temp, count = 0;
    bool find = false;
    cin >> m;
    temp = m;
    
    while (temp) {
      temp /= 10;
      ++count;
    }
    
    for (int i = m - 9 * count; i < m; ++i) {
      if (generator(i) == m) {
        cout << i << endl;
        find = true;
        break;
      }
    }
    
    if (!find) {
      cout << '0' << endl;
    }

  }
  return 0;
}

int generator(int n) {
  int ans = n;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}                                 
