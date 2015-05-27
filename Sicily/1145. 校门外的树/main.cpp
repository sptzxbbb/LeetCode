// soj: 1145. 校门外的树
// Sat Nov 29, 2014--------Shawn Chow
#include "iostream"
using namespace std;

const int MAX = 10001;

int main(int argc, char *argv[]) {
  int road[MAX] = {};
  int L, M, start, end;
  cin >> L >> M;
  L++;
  for (int i = 0; i < M; ++i) {
    cin >> start >> end;
    for (int j = start; j <= end; ++j) {
      if (road[j] == 0) {
	L--;
	road[j] = 1;
      }
    }
  }
  cout << L << endl;
  return 0;
}
