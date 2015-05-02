// soj: 1484. 守望者的逃离
// Thu Dec 4, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int main(int argc, char *argv[]) {
  int M, S, T;
  while (cin >> M >> S >> T) {
    int dis = 0, time = 0;
    bool ans = false;
    while (M >= 10) {
      M -= 10;
      S -= 60;
      T--;
      dis += 60;
      time++;
      if (T == 0 && S > 0) {
	cout << "No" << endl << dis << endl << endl;
	ans = true;
	break;
      }
      if (S <= 0) {
	cout << "Yes" << endl << time << endl << endl;
	ans = true;
	break;
      }
    }
    if (ans) break;
    while (T) {
      if (M >= 6 && T >= 2 && S > 34) {
	T -= 2;
	S -= 60;
	M -= 6;
	dis += 60;
	time += 2;
      } else if (M >= 2 && T >= 3 && S > 51) {
	T -= 3;
	S -= 60;
	M -= 2;
	dis += 60;
	time += 3;
      } else if (M < 2 && T >= 7 && S > 119) {
	T -= 7;
	S -= 120;
	dis += 120;
	time += 7;
      } else {
	T--;
	S -= 17;
	dis += 17;
	time++;
      }

      if (S <= 0) {
	cout << "Yes" << endl << time << endl << endl;
	ans = true;
	break;
      }
      if (ans) break;
      if (T == 0) {
	cout << "No" << endl << dis << endl << endl;
	ans =true;
	break;
      }
      if (ans) break;
    }
  }
}
