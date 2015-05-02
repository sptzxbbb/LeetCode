#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
  string s;
  while(getline(cin,s))
    {
      if(s=="")
	{
	  cout<<endl;
	  continue;
	}
      int count=0,len=s.length();
      bool b=true;
      for(int i=0;i<len;i++)
	{
	  if(isdigit(s[i]))
	    {
	      if(i+1<len&&isdigit(s[i+1]))
		{
		  if(i+2<len&&isdigit(s[i+2]))
		    {
		      b=false;
		      break;
		    }
		  else
		    {
		      count+=(s[i]-'0')*10+s[i+1]-'0';
		      i+=2;
		    }
		}
	      else
		{
		  count+=s[i]-'0';
		  i++;
		}
	    }
	  else count++;
	}
      if(count>50) b=false;
      if(b==false)
	{
	  cout<<"TOO LONG"<<endl;
	  continue;
	}
      for(int i=0;i<len;i++)
	{
	  if(isdigit(s[i]))
	    {
	      if(i+1<len&&isdigit(s[i+1]))
		{
		  for(int j=0;j<(s[i]-'0')*10+s[i+1]-'0';j++)
		    cout<<s[i+2];
		  i+=2;
		}
	      else 
		{
		  for(int j=0;j<s[i]-'0';j++)
		    cout<<s[i+1];
		  i++;
		}
	    }
	  else cout<<s[i];
	}
      cout<<endl;
    }
  return 0;
}
