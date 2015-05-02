/* source code of submission 428002, Zhongshan University Online Judge System */
#include <stdio.h>
char  bit[25];
int  len;
int  n;
void tobase3(int n)
{
  if ( n<0 )
    {
      n=-n;
    }
  len=-1;
  while ( n>0)
    {
      bit[++len]=n%3+'0';
      n/=3;
    }
  for (int i=len+1; i<25; ++i)
    {
      bit[i]='0';
    }
}
void  adjust()
{
  for (int i=0; i<=len; ++i)
    {
      if ( bit[i]=='3' )
        {
	  bit[i]='0';
	  ++bit[i+1];
        }
      else if ( bit[i]=='2' )
        {
	  bit[i]='-';
	  ++bit[i+1];
        }
    }
  if ( bit[len+1]>'0' )
    {
      ++len;
    }
}
void output()
{
  if ( n>=0 )
    {
      for (int i=len; i>=0; --i)
        {
	  printf("%c", bit[i]);
        }
    }
  else
    {
      for (int i=len; i>=0; --i)
        {
	  switch ( bit[i] )
            {
            case '1': printf("-");  break;
            case '-': printf("1");  break;
            case '0': printf("0");  break;
             
            }
        }
    }

  printf("\n");
}
int main(int argc, char *argv[])
{
  while ( scanf("%d", &n)!=EOF )
    {
      if ( n==0 )
        {
	  printf("0\n");
	  continue;
        }
      tobase3(n);
      adjust();
      output();
    }
  return 0;
}
