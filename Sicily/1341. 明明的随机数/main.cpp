// soj: 1341. 明明的随机数
// Sun Nov 30, 2014--------Shawn Chow


#include<stdio.h>
int main() {
  int n, i, num[102], j, ans[102], temp, count = 1;
  while (scanf("%d", &n) != EOF) {
    count = 1;
    for (i = 1; i <= n; i++) {
      scanf("%d", &num[i]);
    }
    for (i = 1; i <= n - 1; i++) {
      for (j = i + 1; j <= n; j++) {
	if (num[i] > num[j]) {
	  temp = num[i];
	  num[i] = num[j];
	  num[j] = temp;
	}
      }
    }
    ans[count] = num[1];
    for (i = 2; i <= n; i++)  {
      if (num[i] != ans[count]) {
	ans[++count] = num[i];
      }
    }
    printf("%d\n", count);
    for (i = 1; i <= count; i++) {
      if (i != count) {
        printf("%d ", ans[i]);
      } else {
        printf("%d", ans[i]);
      }
    }
    printf("\n");
    for (i = 1; i <= 101; i++) {
      num[i] = ans[i] = 0;
    }
  }
}
