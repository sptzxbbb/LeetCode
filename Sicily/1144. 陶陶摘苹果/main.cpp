// soj: 1144. 陶陶摘苹果
// Sat Nov 29, 2014--------Shawn Chow

#include <stdio.h>
int main() {
  int i, apple[10], height, ans = 0;
  for (i = 0; i <= 9; i++)  scanf("%d", &apple[i]);
  scanf("%d", &height);
  height += 30;
  for (i = 0; i <= 9; i++) {
    if (height >= apple[i]) ans++;
  }
  printf("%d\n", ans);
}                                 
