// soj: 3718. 批改作业
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
#include "vector"
using namespace std;

int main(int argc, char *argv[]) {
  double n, m, sum, score;
  vector<double> gpa;
  int count = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    sum = 0;
    for (int j = 0; j < m; ++j) {
      cin >> score;
      sum += score;
    }
    sum /= m;
    if (sum < 60) ++count;
    gpa.push_back(sum);
  }
  cout.precision(2);
  cout << fixed;
  for (int i = 0; i < n; ++i) {
    cout << gpa[i] << endl;
  }
  cout << count << endl;
  return 0;
}
