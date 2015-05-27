// soj: 1346. 金明的预算方案
// Wed Dec 10, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int N, m;
  while (cin >> N >> m) {
    int price[m + 1], value[m + 1], attach[m + 1], important, budget[N + 1];
    bool purchase[m + 1];
    for (int i = 1; i <= m; ++i) {
      cin >> price[i] >> important >> attach[i];
      value[i] = price[i] * important;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = N; j >= 0; --j) {
	
      }
    }

    
    
  }

  return 0;
}

