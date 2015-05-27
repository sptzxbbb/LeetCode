#include "cstdio"
#include "cstring"
using namespace std;

const int MAX = 10000000;
int ans[100000] = {0};
bool prime[MAX + 1];

void makePrime();
bool pali(int a);
void generate();

int main(int argc, char *argv[]) {
  makePrime();
  generate();
  int a, b;
  while (scanf("%d %d", &a, &b), a != 0 && b != 0) {
    int count = 0;
    while (ans[count] <= b && ans[count] != 0) {
      if (ans[count] >= a) printf("%d\n", ans[count]);
      ++count;
    }
  }
  return 0;
}

void makePrime() {
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i < MAX; ++i) {
    int temp = 2 * i;
    if (prime[i]) {
      while (temp <= MAX) {
        prime[temp] = false;
        temp += i;
      }
    }
  }
}

bool pali(int a) {
  int b = a, temp = 0;
  do {
    temp = temp * 10 + b % 10;
    b /= 10;
  } while (b);

  if (a == temp) return true;
  return false;
}

void generate() {
  int count = 0;
  for (int i = 5; i <= MAX; ++i) {
    if (prime[i] && pali(i)) {
      ans[count] = i;
      ++count;
    }
  }
}
