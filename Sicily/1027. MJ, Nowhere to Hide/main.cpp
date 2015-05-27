// soj: 1027. MJ, Nowhere to Hide
// Sat Nov 29, 2014--------Shawn Chow
#include <stdio.h>
#include <string.h>

int main() {
  int n = 1, i, j, k = 0;
  char IP[21][100], ID[21][100], main[11][100], Majia[11][100], temp[100];
  while (n != 0) {
    k = 0;
    scanf("%d", &n);
    if (n == 0) return 0;
    for (i = 1; i <= n; i++) {
      scanf("%s%s", ID[i], IP[i]);
    }
    for (i = 1; i <= n - 1; i++) {
      for (j = i + 1; j <= n; j++) {
	if (strcmp(IP[i], IP[j]) == 0) {
	  sprintf(Majia[k],"%s", ID[j]);
	  sprintf(main[k++], "%s", ID[i]);
	}
	continue;
      }
    }
    for (i = 0; i <= k - 2; i++) {
      for (j = i + 1; j <= k - 1; j++) {
	if (strcmp(main[i], main[j]) > 0) {
	  sprintf(temp, "%s", main[i]);
	  sprintf(main[i], "%s", main[j]);
	  sprintf(main[j], "%s", temp);
	  sprintf(temp, "%s", Majia[i]);
	  sprintf(Majia[i], "%s", Majia[j]);
	  sprintf(Majia[j], "%s", temp);
	}
      }
    }
    for (i = 0; i <= k - 1; i++) {
      sprintf(temp, "%s is the MaJia of %s", Majia[i], main[i]);
      printf("%s\n", temp);
    }
    printf("\n");
  }
}                                 
