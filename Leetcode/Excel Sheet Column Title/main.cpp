#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
      string s = "";
      char c;
      while (n) {
        --n;
        c = n % 26 + 'A';
        n /= 26;
        s = c + s;
      }
      return s;
    }
};

int main(int argc, char *argv[]) {
  Solution k;
  cout << k.convertToTitle(28) << endl;
  return 0;
}

