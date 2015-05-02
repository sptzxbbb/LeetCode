#include "iostream"
#include "string"
#include "sstream"
using namespace std;

class Solution2 {
public:
  int compareVersion(string version1, string version2) {
    stringstream s1, s2;
    double a1, a2;
    version1 += ".0";
    version2 += ".0";
    while (version1 != "0" && version2 != "0") {
      s1 << version1;
      s2 << version2;
      s1 >> a1;
      s2 >> a2;
      if (a1 > a2) return 1;
      else if (a1 < a2) return -1;
      else {  // a1 == a2
        zero(version1);
        zero(version2);
      }
      s1.str("");
      s2.str("");
    }
    return 0;
  }
  
  void zero(string& s) {
    size_t pos = s.find('.');
    // can't find the first separtor
    if (pos == string::npos) return; 
    pos = s.find('.', pos + 1);
    // can't find the second separtor
    if (pos == string::npos) {
      s = "0";
    } else {  // find it
      s = "0" + s.substr(pos, s.size() - pos);
    }
  }
};

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int val1, val2;
    int idx1 = 0, idx2 = 0;
    while (idx1 < version1.length() || idx2 < version2.length()) {
      val1 = 0; 
      while (idx1 < version1.length()) {
        if (version1[idx1] == '.') {
          ++idx1;
          break;
        }
        val1 = val1 * 10 + (version1[idx1] - '0');
        ++idx1;
      }
      val2 = 0; 
      while (idx2 < version2.length()) {
        if (version2[idx2] == '.') {
          ++idx2;
          break;
        }
        val2 = val2 * 10 + (version2[idx2] - '0');
        ++idx2;
      }
      if (val1 > val2) return 1;
      if (val1 < val2) return -1;
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  string s1 = "1.01", s2 = "1.001";
  Solution a;
  cout << a.compareVersion(s1, s2) << endl;
  return 0;
}
