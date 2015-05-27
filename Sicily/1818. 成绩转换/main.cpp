// soj: 1818. 成绩转换
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "map"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    map<string, int> score;
    string s;
    int a;
    for (int i = 0; i < n; ++i) {
      cin >> s >> a;
      score[s] = a;
    }

    for (int i = 0; i < m; ++i) {
      cin >> s;
      if (score[s] <= 100 && score[s] >= 90) cout << 'A' << endl;
      else if (score[s] <= 89 && score[s] >= 80) cout << 'B' << endl;
      else if (score[s] <= 79 && score[s] >= 70) cout << 'C' << endl;
      else if (score[s] <= 69 && score[s] >= 60) cout << 'D' << endl;
      else if (score[s] <= 59 && score[s] >= 0) cout << 'E' << endl;
      else cout << "Score is error!" << endl;
    }
  }
  return 0;
}
