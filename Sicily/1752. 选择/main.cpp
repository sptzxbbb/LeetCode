// soj: 1752. 选择
// Sat Nov 29, 2014--------Shawn Chow
#include <stdio.h>
#include "vector"
#include "iostream"
using namespace std;

vector<int> prime;

int pri(int a) {
  if (0 == prime.size()) {
    prime.push_back(2);
    prime.push_back(3);
  }

  int size = prime.size();
  
  if (prime[size - 1] >= a) {  // a is already in table
    for (int i = 0; i < size; ++i) {
      if (prime[i] == a) return (i + 1);
    }
  } else {  //  a is not yet in the table
    // extend the table
    int next = prime[size - 1];

    while (next != a) {
      next += 2;
      bool isPrime = true;
      for (int i = 0; (prime[i] * prime[i] <= next) && i < size; ++i) {
	if (next % prime[i] == 0) {
	  isPrime = false;
	  break;
	}
      }
      if (isPrime) {
	size++;
	prime.push_back(next);
      }
    }

    return size;
  }
}

int main() {
  while (1) {
    int w = 0;
    scanf("%d", &w);
    if (-1 == w) return 0;
    int ans;
    ans = pri(w);
    cout << ans << endl;
  }
}                                 
