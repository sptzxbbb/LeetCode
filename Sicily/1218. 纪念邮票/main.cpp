// soj: 1218. 纪念邮票
// Sat Nov 29, 2014--------Shawn Chow
#include <stdio.h>
#include <math.h>

int main() {
  int N, M, i, a, b, j;
  double k;
  scanf("%d%d", &N, &M);
  k = 2 * M;
  for (i = sqrt(k); i >= 1; i--) {
    if (2 * M % i == 0) {
      j = 2 * M / i;
      a = (j - i + 1) / 2;
      b = (i + j - 1) / 2;
      if (b <= N && (a + b) * (b - a + 1) == 2 * M)
	printf("[%d,%d]\n", a, b);
    }
  }
}                                 
