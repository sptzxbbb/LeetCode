// soj: 3912. 计算星期几
// Sun Nov 30, 2014

#include <stdio.h>
const int calendar[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int T, month, day, time, i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &month, &day);
    time = 5;
    for (i = 1; i < month; i++) {
      time += calendar[i];
    }
    time += day;
    time %= 7;
    switch (time) {
    case 1: printf("Monday\n");
      break;
    case 2: printf("Tuesday\n");
      break;
    case 3: printf("Wednesday\n");
      break;
    case 4: printf("Thursday\n");
      break;
    case 5: printf("Friday\n");
      break;
    case 6: printf("Saturday\n");
      break;
    case 0: printf("Sunday\n");
      break;
    }
  }
}
