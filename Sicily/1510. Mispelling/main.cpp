// soj: 1510. Mispelling
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int M, count = 0;
    char s[80];
    cin >> M;
    cin >> s;
    cout << i << ' ';
    while (s[count] != '\0') {
      if (count != M - 1) cout << s[count];
      count++;
    }
    cout << endl;
  }
  return 0;
}
