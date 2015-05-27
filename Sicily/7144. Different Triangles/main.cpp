// soj: 7144. Different Triangles
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    int data[m];
    for (int i = 0; i < m; ++i) {
      cin >> data[i];
    }

    int count = 0;
    for (int i = 0; i < m - 2; ++i) {
      for (int j = i + 1; j < m - 1; ++j) {
	for (int k = j + 1; k < m; ++k) {
	  if (data[i] + data[j] > data[k] &&
	      data[i] + data[k] > data[j] &&
	      data[j] + data[k] > data[i] ) ++count;
	}
      }
    }
    cout << count << endl;
  }
  return 0;
}
