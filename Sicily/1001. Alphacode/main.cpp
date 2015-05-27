// soj 1001.Alphacode--------Shawn Chow
// Web Nov 27, 2014;
#include "iostream"
#include "string"
using namespace std;

bool permuta(char a, char b);

int main(int argc, char *argv[]) {
  string S;
  cin >> S;
  while (S[0] != '0') {
    int s[3], c[3], size = S.size();
    s[0] = s[1] = 1;
    c[0] = c[1] = 0;
    
    for (int i = 2; i <= size; ++i) {
      if (S[i - 1] != '0') {	
	s[2] = s[1] + c[1];
	if (S[i - 2] != '0' && permuta(S[i - 2], S[i - 1])) {
	  c[2] = s[0] + c[0];
	} else {
	  c[2] = 0;
	}
      } else { // s[i - 1] = '0'
	s[2] = 0;
	c[2] = c[0] + s[0];
      }
      s[0] = s[1];
      s[1] = s[2];
      c[0] = c[1];
      c[1] = c[2];
    }
    cout << c[2] + s[2] << endl;
    cin >> S;
  }
  return 0;
}


bool permuta(char a, char b) {
  int ans;
  ans = (a - '0') * 10 + (b - '0');
  return ans <= 26 ? true : false;
}

