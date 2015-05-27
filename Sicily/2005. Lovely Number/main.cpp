// soj: 2005. Lovely Number
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
#include "set"
using namespace std;

int main(int argc, char *argv[]) {
  int n, temp;
  while (cin >> n) {
    set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      if (s.find(temp) == s.end()) s.insert(temp);
      else s.erase(temp);
    }
    cout << *(s.begin()) << endl;
  }
  return 0;
}
