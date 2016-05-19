// soj: 1203. The Cubic End
// Sat Dec 6, 2014--------Shawn Chow

#include "iostream"
using namespace std;
long long cube(long long a, long long mod);
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    long long m, size = 0, temp;
    cin >> m;
    temp = m;
    while (temp != 0) {
      temp /= 10;
      ++size;
    }
    
    long long modulus[size], k, weight = 10, pos = 1;
    temp = 10;
    for (int i = 0; i < size; ++i) {
      modulus[i] = m % temp;
      temp *= 10;
    }

    switch (modulus[0]) {
    case 1:
      k = 1;
      break;
    case 3:
      k = 7;
      break;
    case 7:
      k = 3;
      break;
    case 9:
      k = 9;
      break;
    }

    while (pos != size) {
      k += weight;
      if (cube(k) % (weight * 10) == modulus[pos]) {
    	pos++;
    	weight *= 10;
      }
    }
    cout << k << endl;
  }

  return 0;
}

const int ten = 1000000000;

long long cube(long long a) {
  long long temp = a, ans, last;
  if (temp >= ten) {
    long long a, b;
    a = temp / ten % 10 * ten;
    b = temp % ten;
    last = b * b % mod * b % mod + 3 * (a * (b * b % ten) % mod) % mod;
  } else {
    last = temp * temp % mod * temp % mod;
  }
  return last;
}

// 1 * 1 * 1 = 1,   3 * 3 * 3 = 27,     7 * 7 * 7 = 343,  9 * 9 * 9 = 729

// (a + b)^3 mod c == b^3 mod c + 3 * a * b^2 mod c
// (a + b)^3 =  3ab^2 + b^3
