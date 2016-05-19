#include "iostream"
using namespace std;

int boyer_moore(int* A, int* B, int m, int n, int* table);
void bc_shift(int* B, int n, int* bc_table);

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    int bc_table[256];
    int B[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> B[i];
    }

    
    bc_shift(B, n, bc_table);
    
    int m;
    cin >> m;
    int A[m + 1];
    for (int i = 1; i <= m; ++i) {
      cin >> A[i];
    }

    int ans = boyer_moore(A, B, m, n, bc_table);


    if (ans > 0) cout << ans << endl;
    else cout << "no solution" << endl;
  }

  return 0;
}

int boyer_moore(int* src, int* pat, int slen, int plen, int* shift) {
  int s_idx = plen, p_idx;
  int skip_stride, match;
  if (plen == 0) return -1;

  while (s_idx <= slen) {
    p_idx = plen;
    match = 0;
    while (src[s_idx] == pat[p_idx]) {
      if (p_idx == 1) return s_idx;
      s_idx--;
      p_idx--;
      match++;
    }

    // src[s_idx] is bad character 
    skip_stride = shift[src[s_idx]] + match;
    s_idx += skip_stride;

    // 1 2 3 4 2 2 4
    // 2 2 3 
    // suppose to skip           :  shift[src[s_idx]]
    // the digit already mathch  :  k
    // result                    :  
    
  }

  return -1;
}

void bc_shift(int* B, int n, int* bc_table) {
  
  for (int i = 0; i < 256; ++i) {
    bc_table[i] = n;
  }

  for (int i = 1; i < n; ++i) {
    bc_table[B[i]] = n - i;
  }
}

//  n   = 5
//  i   = 0 1 2 3 4
//  s = ~~2 3 5 1 4~~~~
//B[i]  = 2 5 1 1 4
//bc[2] = 5 - 1 = 4;
//bc[5] = 5 - 2 = 3;
//bc[1] = 5 - 3 = 2;
//bc[1] = 5 - 4 = 1;
//bc[4] = 5;


// the real shift:   bc[B[i]] - 


//p  =  a b r a c a d a b r a
//bc =  3 2 1 3 6 3 4 3 2 1 11
