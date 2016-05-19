// soj: 1200. Stick
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
#include "set"
using namespace std;

int main(int argc, char *argv[]) {
  int n, temp;
  cin >> n;
  while (n != 0) {
    set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      if (s.find(temp) == s.end()) s.insert(temp);
      else s.erase(temp);
    }
    cout << *s.begin() << endl;
    cin >> n;
  }
  return 0;
}
