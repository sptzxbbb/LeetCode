// source code of submission 672644, Zhongshan University Online Judge System
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std ;

long long mod ;

long long cube3(long long cur)
{
  long long temp = cur ;
  long long last ;
  if(temp >= 1000000000)                                                             // cur = ABCDEFGHIJ^3
    {
      long long a = temp / 1000000000 % 10 * 1000000000 ;        // A000000000
      long long b = temp % 1000000000 ;                                     // BCDEFGHIJ
      last = b * b % mod * b % mod + 3 * (a * ( b * b %  1000000000 ) % mod ) % mod;
    }
  else     //cur^3 
    {
      last = (temp % mod) * ( temp % mod ) % mod * ( temp % mod ) % mod ;
    }
  return last ;
}


int main()
{
  int c ;
  cin >> c ;
  while(c--)
    {
      int len = 0 ;
      long long num , temp;
      cin >> num ;
      temp = num ;
      mod = 1 ;
      while(temp!=0)
        {
	  mod *= 10 ;
	  len ++ ;
	  temp /= 10 ;
        }

      long long cur_mod = 10 ;
      long long result = 1 ;
      for(int i = 0 ; i < len ; i ++ )               //一位一位地向左计算
        {
	  long long add = cur_mod / 10 ;
	  long long last_n = num % cur_mod ;

	  while( cube3(result) % cur_mod != last_n )  //找到后n位满足的数result
            {
	      result += add  ;
            }
	  cur_mod *= 10 ;
        }
      result %= mod ;
      cout << result << endl;
    }
}
