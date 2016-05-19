#include <iostream>
#include <cstdio>
using namespace std;

int next[60010];
int code[60010];
int gate[1000000];

void get_next(int n)                  //求 next 数组， next[j] ＝ k 表示的是在模式串 j 位之前 k 位匹配了模式串开头的 k 位。
{
  int i, j;
     
  i = 0;
  j = -1;
  next[0] = -1;                         //在模式串第 0 位之前没有元素匹配，因此初始化为 -1 。
     
  while (i < n)
    {
      if (j == -1 || code[i] == code[j])
	{
	  i ++;
	  j ++;
                 
	  next[i] = j;
	}
      else
	j = next[j];    
    }
}

int kmp(int n, int m)
{
  int i, j;
     
  i = j = 0;
     
  while (i < m && j < n)
    {
      if (gate[i] == code[j])
	{
	  i ++;
	  j ++;
	}
      else  if (next[j] >= 0)
	j = next[j];
      else
	{
	  j = 0;
	  i ++;
	}
           
    }
     
  if (j == n)
    return i - n;
  else
    return -1;
}

int main()
{
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
    
  int n, m;
  int ans;
    
  while (scanf("%d", &n) != EOF)
    {
      for (int i = 0; i < n; i ++)
	scanf("%d", &code[i]);
          
      scanf("%d", &m);
          
      for (int i = 0; i < m; i ++)
	scanf("%d", &gate[i]);
          
      get_next(n);                 //求 next 数组
          
      ans = kmp(n, m);
          
      if (ans == -1)
	printf("no solution\n");
      else
	printf("%d\n", ans);
    }
    
  return 0;
}
