
#include <iostream>

#include <memory.h>
using namespace std;
int M,S,T;
int dis[300001];
int sol()
{
  int r=0;
  for(int i=1;i<=T;i++)
    {
      if(M>9)
	{
	  dis[i]=dis[r]+60;
	  r=i;            
	  M-=10;
	}
      else
	M+=4;
    }
  //      for(int i=0;i<=T;i++)
  //              cout<<dis[i]<<" ";
  //      cout<<endl;
  for(int i=1;i<=T;i++)
    if(dis[i]<dis[i-1]+17)
      dis[i]=dis[i-1]+17;
  //      for(int i=0;i<=T;i++)
  //              cout<<dis[i]<<" ";
  //      cout<<endl;
  if(dis[T]<S)
    {
      cout<<"No"<<endl;
      cout<<dis[T]<<endl;
    }
  else
    {
      int i=0;
      while(dis[i]<S)
	i++;
      cout<<"Yes"<<endl;
      cout<<i<<endl;
    }
         
}
int main()
{
  while(cin>>M>>S>>T)
    {
      memset(dis,0,sizeof(dis));
      sol();
      cout << endl;
    }
}
