// soj: 1240. Faulty Odometer
// Sat Dec 6, 2014--------Shawn Chow

#include "iostream"
#include "string"
#include "list"
using namespace std;

int faculty(int &n) {
  list<int> digit;
  int temp = n, num, ans = 0, exp = 1;
  while (temp != 0) {
    num = temp % 10;
    if (num > 4) --num;
    ans += num * exp;
    exp *= 9;
    digit.push_back(num);
    temp /= 10;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n) {
    int ans = 0;
    ans = faculty(n);
    cout << n << ": " << ans << endl;
    cin >> n;
  }
  return 0;
}


// 2003       100 10 1


// 15:13  23:21   25:22    239:197 250:198

// tenth : 1
// hund  : 19
// 
