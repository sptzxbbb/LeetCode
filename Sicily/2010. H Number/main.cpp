// soj: 2010. H Number
// Thu Dec 18, 2014--------Shawn Chow
#include "iostream"
#include "vector"
using namespace std;

bool h(int a) {
  if (a < 100) return true;
  vector<int> digit;
  int temp;
  do {
    temp = a % 10;
    a /= 10;
    digit.push_back(temp);
  } while (a);

  for (int i = 1; i < digit.size() - 1; ++i) {
    if (digit[i] != (digit[i - 1] + digit[i + 1]) &&
	digit[i] != (digit[i - 1] - digit[i + 1]) &&
	digit[i] != (digit[i + 1] - digit[i - 1])) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int a, count = 0;
  cin >> a;
  for (int i = 1; i <= a; ++i) {
    if (h(i)) ++count;
  }
  cout << count << endl;
  return 0;
}

