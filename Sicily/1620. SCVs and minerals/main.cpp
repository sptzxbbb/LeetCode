// soj: 1620.SCVs and minerals
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int N, M, C, P, S, k;
    cin >> N >> M >> C >> P >> S;
    int mineral[S + 1];
    mineral[0] = M;
    for (int i = 1; i <= S; ++i) {
      if (mineral[i - 1] >= P && (S - i + 1) * C > P) {
	k = (mineral[i - 1]) / P;
 	N += k;
	mineral[i] = mineral[i - 1] + N * C - P * k;
      } else {
	mineral[i] = mineral[i - 1] + N * C;
      }
    }
    cout << mineral[S] << endl;
  }
  return 0;
}



