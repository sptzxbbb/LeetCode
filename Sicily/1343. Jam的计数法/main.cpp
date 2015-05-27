// soj: 1343. Jam的计数法
// Wed Dec 10, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

bool next(int s, int t, string& str) {
  int size = str.size();
  if (str[size - 1] + 1 <= 'a' + t - 1) {
    ++str[size - 1];
    return true;
  }
  
  for (int i = size - 2; i >= 0; --i) {
    if (str[i] + 1 <= 'a' + t - 1 && str[i] + 1 < str[i + 1]) {
      ++str[i];
      for (int j = i + 1; j < size; ++j) {
	str[j] = str[j - 1] + 1;
      }
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  int s, t, w;
  string str;
  while (cin >> s >> t >> w) {
    cin >> str;
    for (int i = 0; i < 5; ++i) {
      if (next(s, t, str)) cout << str << endl;
    }
  }
  return 0;
}
