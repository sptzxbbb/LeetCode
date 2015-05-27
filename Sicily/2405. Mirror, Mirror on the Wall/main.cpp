// soj: 2405. Mirror, Mirror on the Wall
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s, s != "#") {
    bool invalid = false;
    for (int i = 0; i < s.size(); ++i) {
      switch(s[i]) {
      case 'b':
	s[i] = 'd';
	break;
      case 'd':
	s[i] = 'b';
	break;
      case 'p':
	s[i] = 'q';
	break;
      case 'q':
	s[i] = 'p';
	break;
      case 'x':
	break;
      case 'w':
	break;
      case 'o':
	break;
      case 'v':
	break;
      case'i':
	break;
      default:
	invalid = true;
      }
    }
    if (!invalid) {
      for (int i = 0; i < s.size() / 2; ++i) {
	swap(s[i], s[s.size() - i - 1]);
      }
      cout << s << endl;
    } else cout << "INVALID" << endl;
    
  }
  return 0;
}

