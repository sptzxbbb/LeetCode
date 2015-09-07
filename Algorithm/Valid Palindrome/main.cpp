#include "iostream"
using namespace std;

class Solution1 {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      //      while ((s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && i < s.size()) ++i;
      //      while ((s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z') && j >= 0) --j;
      while (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) && i < s.size()) ++i;
      while (!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) && j >= 0) --j;
      if (i >= j) return true;
      // capital and small letter
      if (s[i] != s[j] &&
          s[i] + ('a' - 'A') != s[j] &&
          s[i] - ('a' - 'A') != s[j]) 
        return false;
      ++i;
      --j;
    }
    return true;
  }
};

class Solution {
public:
    bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
	    
	}
    }
};

int main(int argc, char *argv[]) {
  Solution a;
  string s = "A man, a plan, a canal: Panama", s1 = ".,";
  cout << boolalpha << a.isPalindrome(s1) << endl;
  return 0;
}
