// soj: 1624. Cryptoquote
// Tue Dec 16, 2014
#include "iostream"
#include "string"
#include "cstdio"
using namespace std;

int main(int argc, char *argv[]) {
  int n, temp;
  cin >> n;
  getchar();
  temp = n;
  while (n--) {
    string code, table;
    getline(cin, code);
    cin >> table;
    getchar();
    for (int i = 0; i < code.size(); ++i) {
      if (code[i] != ' ') code[i] = table[code[i] - 'A'];
    }
    cout << temp - n << ' ' << code << endl;
  }
  return 0;
}
