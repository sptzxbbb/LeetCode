// soj: 1051. Biker's Trip Odomete
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
using namespace std;

const double pi = 3.1415927;

int main(int argc, char *argv[]) {
  int n, count = 0;
  double d, t;
  while (cin >> d >> n >> t, n != 0) {
    double dis, MPH;
    dis = n * pi * d / (12 * 5280);
    MPH = dis / (t / 3600);
    ++count;
    cout.precision(2);
    cout << fixed << "Trip #" << count << ": " << dis << ' ' << MPH << endl;
  }
  return 0;
}
