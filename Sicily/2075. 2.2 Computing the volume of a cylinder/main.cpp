// soj: 2075. 2.2 Computing the volume of a cylinder
// Tue Dec 16, 2014--------Shawn Chow
#include "iostream"
using namespace std;

const double PI = 3.14159;

int main(int argc, char *argv[]) {
  double num1, num2, volume;
  cin >> num1 >> num2;
  volume = num1 * num1 * PI * num2;
  cout << volume << endl;
  return 0;
}
