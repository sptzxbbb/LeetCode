// soj: 1394. Root of the Problem
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
  int B, N;
  while (cin >> B >> N, B != 0 && N != 0) {
    int A = 1, length1, length2, length3;
    while (1) {
      length1 = abs(B - pow(A - 1, N));
      length2 = abs(B - pow(A, N));
      length3 = abs(B - pow(A + 1, N));
      if (length2 <= length1 && length2 <= length3) break;
      if (length1 <= length2 && length2 <= length3) break;
      ++A;
    }
    cout << A << endl;
  }
 
  return 0;
}


// |B - A^N| <= |B - A^(N+1)| && |B - A^N| <= |B - A^(N - 1)|

// Sample Input

// 4 3   0^3 = 0,  1^3 = 1, 2^3 = 8;
// 5 3
// 27 3
// 750 5
// 1000 5
// 2000 5
// 3000 5
// 1000000 5
// 0 0
// Sample Output

// 1
// 2
// 3
// 4
// 4
// 4
// 5
// 16
