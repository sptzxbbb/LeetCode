// soj: 1007. To and Fro
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n != 0) {
    string s;
    cin >> s;

    int index = 0, size = s.size();
    for (int i = 0; i < n; ++i) {
      index = i;
      cout << s[index];
      while (index < size) {
	index += 2 * (n - i) - 1;
	if (index < size) cout << s[index];
	else break;
	
	index += 2 * i + 1;
	if (index < size) cout << s[index];
	else break;
      }
    }
    cout << endl;
    cin >> n;
  }
  return 0;
}
