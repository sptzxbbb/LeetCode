// soj: 1783. Large is Better
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

bool cmp(char a, char b) {
  if (a > b) return true;
  return false;
}

void large(string& s) {
  string::iterator it1 = s.begin(), it2 = s.begin();
  bool match = false;
  for (int i = 0; i < s.size(); ++i) {
    if (i) ++it2;
    if ('0' == s[i] && match) {
      sort(it1, it2, cmp);
      it1 = it2;
      match = false;
    } else if (s[i] != '0' && !match) {
      it1 = it2;
      match = true;
    } else if (i == s.size() -1 && match) {
      ++it2;
      sort(it1, it2, cmp);
      match = false;
    }
  }
} 

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    large(a);
    cout << a << endl;
  }
  return 0;
}
