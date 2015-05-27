/*
  1009. Mersenne Composite N 梅森素数
  题目大意：
  梅森素数Mn：定义为2n-1其中n为素数且2n-1也为素数的数。
  给定k，求出所有素数n<=k，且满足2n-1不是梅森素数的数，并且将它们分解。
  k<=63
*/
#include <iostream>
#include <cmath>
using namespace std;

//重点1：判断是否是素数，从i=2开始，一直到i*i<=a; 
bool prime(int a)
{
  for(int i=2;i*i<=a;i++)
    if(a%i==0)
      return false;
  return true;
}


int main()
{
  int t;
  cin>>t;
  for(int i=3;i<t;i+=2)
	{
      if(!prime(i)) continue;
      long long s=pow(2.0,i)-1,s2;
      s2=s;
      bool b=0,b2=0;   //重点2：循环体内定义变量，每次进入循环体时都会重新定义； 
      for(long long i=3;i*i<=s;i+=2)
		{
          if(s%i==0&&prime(i))   //s%i==0&&prime(i)
			{
              if(!b2) cout<<i;  //为什么可以保证一定是素数？62之后不能算出？ 
              else cout<<" * "<<i;
              s/=i;   //重点3：循环体内改变循环体参数 for(long long i=3;i*i<=s;i+=2)
              i=3;
              b2++;
              b++;
			}
		}
      if(b)
		{
          cout<<" * "<<s;
          cout<<" = "<<s2<<" = ( 2 ^ "<<i<<" ) - 1"<<endl;
		}
	}
  //system("pause");
  return 0;
}
