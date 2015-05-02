#include<stdio.h>
#include "iostream"
using namespace std;

int m, n;
int s, t;
 
int main()
{
  int road, time;
  while (cin >> m >> s >> t) {
    road = 0;
    m -= m % 2;
    time = t;
    while (t > 0 && road < s)
      {
	if (m == 0)
	  {
	    if (t >= 7 && s - road > 119)
	      {
		t -= 7;
		road += 120;
	      }
	    else
	      {
		t -= 1;
		road += 17;
	      }
	  }
	else if (m == 2)
	  {
	    if (t >= 3 && s - road > 51)
	      {
		t -= 3;
		road += 60;
		m = 0;
	      }
	    else
	      {
		t -= 1;
		road += 17;
	      }
	  }
	else if (m == 4)
	  {
	    if (t >= 3 && s - road > 51)
	      {
		t -= 3;
		road += 60;
		m = 2;
	      }
	    else
	      {
		t -= 1;
		road += 17;
	      }
	  }
	else if (m == 6)
	  {
	    if (t >= 2 && s - road > 34)
	      {
		t -= 2;
		road += 60;
		m = 0;
	      }
	    else
	      {
		t -= 1;
		road += 17;
	      }
	  }
	else if (m == 8)
	  {
	    if (t >= 2 && s - road > 34)
	      {
		t -= 2;
		road += 60;
		m = 2;
	      }
	    else
	      {
		t -= 1;
		road += 17;
	      }
	  }
	else
	  {
	    t -= 1;
	    road += 60;
	    m -= 10;
	  }
      }
    if (road < s) printf("No\n%d\n\n", road);
    else printf("Yes\n%d\n\n", time - t);
  }
  return 0;
}
