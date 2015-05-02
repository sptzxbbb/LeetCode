// soj: 1566. 4SUM
// Sat Dec 13, 2014--------Shawn Chow
#include "cstdio"

int main(int argc, char *argv[]) {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int set1[a], set2[b], set3[c], set4[d];
  for (int i = 0; i < a; ++i) {
    scanf("%d", &set1[i]);
  }
  for (int i = 0; i < b; ++i) {
    scanf("%d", &set2[i]);
  }
  for (int i = 0; i < c; ++i) {
    scanf("%d", &set3[i]);
  }
  for (int i = 0; i < d; ++i) {
    scanf("%d", &set4[i]);
  }

  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      for (int k = 0; k < c; ++k) {
	for (int l = 0; l < d; ++l) {
	  if (set1[i] + set2[j] + set3[k] + set4[l] == 0) {
	    printf("%d %d %d %d\n", set1[i], set2[j], set3[k], set4[l]);
	    return 0;
	  }
	}
      }
    }
  }
  return 0;
}

