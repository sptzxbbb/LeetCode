// soj: 1029. Rabbit
// Sat Nov 29, 2014--------Shawn Chow
#include <stdio.h>
#include <string.h>
#define Max(a, b) (a) > (b) ? (a) : (b)

void addition(char a[], char b[], char c[]) {
  int length_a, length_b, length, i, carry = 0;
  char a_[1000], b_[1000];
  sprintf(a_, "%s", a);
  sprintf(b_, "%s", b);
  length_a = strlen(a) - 1;
  length_b = strlen(b) - 1;
  length = Max(length_a, length_b) + 1;
  for (i = length; i >= 0; i--) {
    if (length_a >= 0) a_[i] = a[length_a--];
    else a_[i] = '0';
    if (length_b >= 0) b_[i] = b[length_b--];
    else b_[i] = '0';
    c[i] = ((a_[i] - '0') + (b_[i] - '0') + carry) % 10 + '0';
    carry = ((a_[i] - '0') + (b_[i] - '0') + carry)  / 10;
  }
  if (c[0] == '0') {
    for (i = 0; i <= length -1; i++) {
      c[i] = c[i + 1];
    }
    c[length] = '\0';
  }
  c[length + 1] = '\0';
}

int main() {
  int m, d, i;
  char rabbit[101][1000] = {"2", "2"}, str[] = {"1"};
  while (1) {
    scanf("%d%d", &m, &d);
    if (d == 0) {
      return 0;
    }
    for (i = 1; i <= d; i++) {
      if (i <= m && i != 1) addition(rabbit[i - 1], str, rabbit[i]);
      if (i > m) addition(rabbit[i - 1], rabbit[i - m], rabbit[i]);
    }
    puts(rabbit[d]);
  }
}                                 
