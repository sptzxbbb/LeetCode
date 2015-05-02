// soj: 2001. Scavenger Hunt
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main(int argc, char *argv[]) {
  int P, Q;
  cin >> P >> Q;

  vector<int> factor1, factor2;
  for (int i = 1; i * i <= P; ++i) {
    if (P % i == 0) {
      factor1.push_back(i);
      if (P != i * i) factor1.push_back(P / i);
    } 
  }
  for (int i = 1; i * i <= Q; ++i) {
    if (Q % i == 0) {
      factor2.push_back(i);
      if (Q != i * i) factor2.push_back(Q / i);
    }
  }
  sort(factor1.begin(), factor1.end());
  sort(factor2.begin(), factor2.end());
  for (int i = 0; i < factor1.size(); ++i) {
    for (int j = 0; j < factor2.size(); ++j) {
      cout << factor1[i] << ' ' << factor2[j] << endl;
    }
  }

  return 0;
}
