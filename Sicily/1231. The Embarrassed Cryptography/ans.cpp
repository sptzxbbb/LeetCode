// source code of submission 784711, Zhongshan University Online Judge System
#include <iostream>
#include <string>
#include "cstring"
using namespace std;

const int SIZE = 1000000;
bool Prime[SIZE + 1];
bool is_mod(string s,int n)         
{
  int ans = 0;
  for(int i = 0;i < s.size();i++)
    ans = (ans*10 + s[i]-'0') % n;
  if(!ans) return 1;
  else return 0;
}
void PrimeTable() {
  memset(Prime, true, sizeof(Prime));
  int n = 2;
  for (int i = 2; i * i <= SIZE; ++i) {
    if (Prime[i]) {
      n = 2 * i;
      while (n <= SIZE) {
	Prime[n] = false;
	n += i;
      }
    }
  }
}

int main()
{
  int k,l,i,res,ok;
  string s;
  PrimeTable();
  while(cin>>s>>l,(s[0]!='0'||l))
    {
      ok = 1;
      for(i = 2;i<=SIZE;i++)
	if(Prime[i] && i < l && is_mod(s, i))  {
	  res = i; 
	  ok = 0; 
	  break;
	}
      if(!ok)  cout<<"BAD"<<" "<<res<<endl;
      else cout<<"GOOD"<<endl;
    }

  return 0;
}
