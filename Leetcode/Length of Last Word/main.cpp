#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Solution1 {
public:
  int lengthOfLastWord(const char *s) {
    int ans = 0;
    bool word = false;
    const char* p = s;
    while (*p != '\n') {
      if ((*p >= 'a' && *p <= 'z') || 
          (*p >= 'A' && *p <= 'Z')) {
        if (!word) {  // new word
          word = true;
          ans = 0;
        }
        ++ans;
      }
      if (' ' == *p && word) word = false; 
      ++p;
    }
    return ans;
  }
};

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int n = strlen(s) - 1;
    while (n >= 0 && ' ' == s[n]) --n;
    
    int i = 0;
    while (n >= 0 && s[n] != ' ') {
      --n;
      ++i;
    }
    return i;
  }
};

int main(int argc, char *argv[]) {
  Solution k;
  const char *s = "a ab";
  cout << k.lengthOfLastWord(s) << endl;
  return 0;
}
