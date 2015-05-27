#include <iostream>
#include <cstring>
using namespace std;

int n,m,d,arr[1002],vis[1002]; //arr储存答案，vis记录是否访问过某位置
bool b;//判断答案是否存在

bool prime(int x)
{
  for(int i=2;i*i<=x;++i)
    if(x%i==0)
      return false;
  return true;
}

bool check(int pos,int s)//判断s是否可以放在arr[pos]上
{
  for(int i=pos-1;i>=0&&i>=pos-d+1;--i)
    {
      s+=arr[i];
      if(prime(s))
	return false;
    }
  return true;
}

void huisu(int pos)
{
  for(int i=n;i<=m;++i)
    {
      if(vis[i]==0&&check(pos,i))
	{
	  vis[i]=1;
	  arr[pos]=i;
	  if(pos==m-n)
	    {
	      b=1;
	      return ;
	    }
	  huisu(pos+1);
	  if(b==1)
	    return;//最后一次调用结束，逐级返回
	  vis[i]=0;
	}
    }
}

int main()
{
  while(cin>>n>>m>>d&&n)
    {
      b=0;
      memset(vis,0,sizeof(vis));
      huisu(0);
      if(b)
	{
	  cout<<arr[0];
	  for(int i=1;i<=m-n;i++)
	    cout<<","<<arr[i];
	  cout<<endl;
	}
      else
	cout<<"No anti-prime sequence exists."<<endl;
    }
  return 0;
}
