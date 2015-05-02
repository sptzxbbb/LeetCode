// soj: 1372. Bovine Latin
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  string word;
  cin >> n;
  while (n--) {
    cin >> word;
    if ('a' == word[0] || 'e' == word[0] || 'i' == word[0] || 'o' == word[0] || 'u' == word[0]) {
      word += "cow";
    } else {
      word += word[0];
      word += "ow";
      word.erase(0, 1);
    }
    cout << word << endl;
  }
  return 0;
}


