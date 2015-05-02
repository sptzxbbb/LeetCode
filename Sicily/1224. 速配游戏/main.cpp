// soj: 1224. 速配游戏
// Sun Dec 7, 2014--------Shawn Chow
#include "cstring"
#include "cstdio"
using namespace std;

int N, i, j, temp, man[1001][1001], woman[1001][1001];
int nextPro[1001] = {0}, match[1001] = {0};
void propose(int n);

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) {
    for (j = 1; j <= N; ++j) {
      scanf("%d", &man[i][j]);
    }
  }

  for (i = 1; i <= N; ++i) {
    for (j = 1; j <= N; ++j) {
      scanf("%d", &temp);
      woman[i][temp] = N - j + 1;
    }
  }

  for (i = 1; i <= N; ++i) propose(i);
  for (i = 1; i <= N; ++i) printf("%d\n", man[i][nextPro[i]]);
  return 0;
}

void propose(int n) {
  int female= man[n][++nextPro[n]];
  if (0 == match[female]) match[female] = n;
  else if (woman[female][match[female]] > woman[female][n])
    propose(n);
  else {
    temp = match[female];
    match[female] = n;
    propose(temp);
  }
}
