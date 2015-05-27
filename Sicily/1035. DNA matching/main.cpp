// soj: 1035. DNA matching
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "vector"
using namespace std;

bool match(string a, string b) {
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); ++i) {
      if ((a[i] == 'A' && b[i] != 'T') || (a[i] == 'T' && b[i] != 'A')
          || (a[i] == 'C' && b[i] != 'G') || (a[i] == 'G' && b[i] != 'C')
          ) return false;
    }
    return true;
  } else {
    return false;
  }
}


int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> DNA;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      DNA.push_back(s);
    }
    
    int ans = 0;
    while (!DNA.empty()) {
      vector<string>::iterator it1 = DNA.begin(), it2 = it1;
      ++it2;
      
      while (it2 != DNA.end()) {
        if (match(*it1, *it2)) break;
        ++it2;
      }
      
      if (it2 == DNA.end()) DNA.erase(it1);
      else {
        ++ans;
        DNA.erase(it2);
        DNA.erase(it1);
      }
    }
    cout << ans << endl;
    
  }
  return 0;
}
