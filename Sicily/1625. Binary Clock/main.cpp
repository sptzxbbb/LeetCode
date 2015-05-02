// soj: 1625. Binary Clock
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "string"
using namespace std;

void turn(int& a, string& s);

int main(int argc, char *argv[]) {
  int n, k = 1;
  cin >> n;
  while (n--) {
    int h, m, s;
    string hour, minute, second;
    char colon;
    cin >> h >> colon >> m >> colon >> s;
    turn(h, hour);
    turn(m, minute);
    turn(s, second);
    cout << k << ' ';
    for (int i = 0; i < 6; ++i) {
      cout << hour[i] << minute[i] << second[i];
    }
    cout << ' ';
    cout << hour << minute << second << endl;
    ++k;
  }
  return 0;
}

void turn(int& t, string& s) {
  int reminder;
  char c;
  for (int i = 0; i < 6; ++i) {
    reminder = t % 2;
    t /= 2;
    c = '0' + reminder;
    s = c + s;
  }
}

