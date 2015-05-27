// 题意: A是主串,B是子串,都由数字组成, 查询B串在A串第一次出现的位置,若找不到则输出no solution
// 注意子串的最大长度是60000,但主串的长度未知,所以要开大些

#include <iostream>        //KMP算法
#include<stdio.h>
using namespace std;
int A[10000],B[80000];    //A是主串,B是子串,查询B串在A串的哪些地方出现
int n,m,next[80000];        //n,m分别是A，B的串长度，A，B的下标是从1开始的
void get_next()
{
  next[1]=0;
  int j=0;
  for(int i = 2; i <= m; ++i)
    {
      while(j > 0 && B[j+1] != B[i])
	j = next[j];
      if(B[j+1] == B[i])
	j = j + 1;
      next[i] = j;
    }
}
void kmp() {
  int j = 0;
  for(int i=1;i<=n;++i) {  // i->A, j->B
    
    while(j > 0 && B[j+1] != A[i]) j = next[j]; // j skip to next[j]
    
    if(B[j+1] == A[i]) j++;
    
    if(j == m) {
      printf("%d\n",i-m); 
      return ;
    }
  }
  printf("no solution\n");
}
int main()
{
  while(scanf("%d",&m)!=EOF)
    {
      for(int i=1;i<=m;++i)
	scanf("%d",&B[i]);
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
	scanf("%d",&A[i]);
      get_next();
      kmp();
    }
  return 0;
}
