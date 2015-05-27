// soj: 1087. A Funny Game
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n) {
    if (n >= 3) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    cin >> n;
  }
  return 0;
}


//  n = 3,     who take first, who lose
//  n = 1, 2    who take first , who win
//  n > 3  (1) n is even

