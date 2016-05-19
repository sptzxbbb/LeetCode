//找规律 算m到n有数字中有几个0，包括m n
//先设数组 dp[i]表示 i长度，第一个固定且非0的所有数字的0的个数
//基于dp从，dp和可以直接算 0到1000000 ，不包括100000
//剩下的数字由高位向低位算，分0和非0去暴力就可以了
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long m, n;
long long result;
long long dp[17];
long long act[17];

long long f(long long k) {
  long long k2 = k;
  if(k == -1) return 0;

  long long result = 0;
  long long temp[34], m = 0;
  while(k) {
    temp[m++] = k % 10;
    k /= 10;
  }
  // [0, (x - 1)999..999]
  result += 1;
  for(int i = 1; i <= m - 1; i++) result += 9 * dp[i];
  result += (temp[m - 1] - 1) * dp[m];
  // [x000...000, xabcd...efg]
  for( int i = m - 2; i >= 0; i--) {
    if(temp[i] > 0) result += (act[i] + temp[i] * dp[i+1]);
    else result += k2 % act[i] + 1;
  }
  return result;
}

int main() {
  act[0] = 1;
  for(int i = 1; i <= 16; i++) act[i] = act[i - 1] *10;

  dp[1] = 0; dp[2] = 1;
  for( int l = 3;l <= 16;l++ ) {
    dp[l] = dp[l-1]*10 + act[l-2];
  }

  while(scanf("%lld%lld",&m,&n) && m >= 0) {
    //f(n);
    printf("%lld\n", f(n) - f(m-1));
  }

  return 0;
}
