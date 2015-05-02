//  1282.Computer Game--------Shawn Chow
//  Thu Nov 27, 2014
#include "iostream"
using namespace std;

void get_next(int* B, int* next, int n);
int kmp(int* A, int* B, int m, int n, int* next);

int main(int argc, char *argv[]) {
  int n, ans;
  while (cin >> n) {
    int B[n], next[n];
    for (int i = 0; i < n; ++i) {
      cin >> B[i];
    }

 
    int m;
    cin >> m;
    int A[m];
    for (int i = 0; i < m; ++i) {
      cin >> A[i];
    }
  
    get_next(B, next, n);

    // for (int i = 0; i < n; ++i) {
    //   cout << next[i] << ' ';
    // }
    // cout << endl;

    ans = kmp(A, B, m, n, next);
    if (ans >= 0) {
      cout << ans << endl;
    } else {
      cout << "no sulution" << endl;
    }

    return 0;
  }
}

void get_next(int* B, int* next, int n) {
  next[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (next[i - 1]) {
      if (B[i] == B[next[i - 1]]) {
	next[i] = next[i - 1] + 1;
      } else if (B[i] == B[0]) {
	next[i] = 1;
      } else {
	next[i] = 0;
      }
    } else {   //  new start
      if (B[i] == B[0]) next[i] = 1;
      else next[i] = 0;
    }
  }
}

int kmp(int* A, int * B, int m, int n, int* next) {
  int i, j;
  i = j = 0;
  while(1) {
    if (j == n) return (i - j);
    if (i == m) return -1;
    
    if (A[i] == B[j]) {
      i++;
      j++;
    } else {
      if (j > 0) {
	if (next[j - 1]) j = next[j - 1];
	else j = 0;
      } else {
	i++;  // A[i] != B[0] ,   i++
      }
    }
  }

}
