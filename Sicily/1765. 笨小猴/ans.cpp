#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool IsPrime(int test)
{
  if(test <= 1)//0,1不是素数
    return false;
  for(int i = 2; i <= sqrt((double)test); i++)
    {
      if(test % i == 0)
	return false;
    }
  return true;
}

int main() {
  string word;
  while(cin >> word) {
    //只要有单词输入就继续判断

      int counter[26] = {0};//表示每个字母出现的次数；[0]代表‘a’
      for(int i = 0; i < word.length(); i++)//统计次数
	{
	  //'a'的ASCII 值为97
	  counter[word[i] - 'a']++;
	}
      int max = 0;
      int min = 100;//长度为100
      for(int i = 0; i < 26; i++)//找出最大、最小值
	{
	  if(counter[i] > max)
	    max = counter[i];

	  if(counter[i] < min && counter[i] != 0)
	    min = counter[i];
	}
      if(max == word.length())//********关键
	min = max;
      int interval = max - min;
      if(IsPrime(interval))
	{
	  cout << "Lucky Word" << endl;
	  cout << interval << endl;
	}
      else
	{
	  cout << "No Answer" << endl;
	  cout << 0 << endl;
	}
    }
}
