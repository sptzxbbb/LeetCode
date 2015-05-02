// soj: 1689. My Summary
// Fri Dec, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "set"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, temp;
    char problem;
    string state;
    set<char> AC, WA;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> temp >> problem >> state;
      if ("Accept" == state) AC.insert(problem);
      else WA.insert(problem);
    }
    cout << "Accept: ";
    set<char>::iterator it1 = AC.begin();
    while (it1 != AC.end()) {
      WA.erase(*it1);
      cout << *it1;
      ++it1;
    }
    cout << endl << "Wrong: ";
    it1 = WA.begin();
    while (it1 != WA.end()) {
      cout << *it1;
      ++it1;
    }
    cout << endl << endl;
  }
  return 0;
}
