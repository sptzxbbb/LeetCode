// soj: 1395. Rounders
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    string num;
    int carry = 0;
    cin >> num;
    if (num.size() >= 2) {
      for (int i = num.size() - 1; i >= 1; --i) {
	if (num[i] + carry >= '5') {
	  num[i] = '0';
	  carry = 1;
	} else {
	  num[i] = '0';
	  carry = 0;
	}
      }
      if (carry) {
	++num[0];
	if (num[0] > '9') {
	  num[0] = '0';
	  num = '1' + num;
	}
      }
    }
    cout << num << endl;
  }
  return 0;
}
