// soj: 1014. Specialized Four-Dig
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
using namespace std;

int duo(int N);
int dec(int N);
int hex(int N);

int main(int argc, char *argv[]) {
  for (int i = 1000; i < 10000; ++i) {
    if (duo(i) == dec(i) && dec(i) == hex(i)) cout << i << endl;
  }
  return 0;
}

int duo(int N) {
  int A, B, C, D, sum;
  A = N / (12 * 12 * 12);
  N %= 12 * 12 * 12;
  B = N / (12 * 12);
  N %= 12 * 12;
  C = N / 12;
  N %= 12;
  D = N;
  sum = A + B + C + D;
  return sum;
}

int dec(int N) {
  int A, B, C, D, sum;
  A = N % 10;
  N /= 10;
  B = N % 10;
  N /= 10;
  C = N % 10;
  N /= 10;
  D = N;
  sum = A + B + C + D;
  return sum;
}

int hex(int N) {
  int A, B, C, D, sum;
  A = N / (16 * 16 * 16);
  N %= 16 * 16 * 16;
  B = N / (16 * 16);
  N %= 16 * 16;
  C = N / 16;
  N %= 16;
  D = N;
  sum = A + B + C + D;
  return sum;
}
