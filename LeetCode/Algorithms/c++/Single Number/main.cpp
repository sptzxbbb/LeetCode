#include "algorithm"
#include "iostream"
using namespace std;

class Solution1 {
public:
  int singleNumber(int A[], int n) {
    sort(A, A + n);
    for (int i = 0; i < n; i += 2) {
      if (i == n - 1) return A[i];
      if (A[i] != A[i + 1]) return A[i];
    }
  }
};

class Solution {
public:
  int singleNumber(int A[], int n) {
    int digits[32] = {0};
    for (int i = 0; i < 32; ++i) {
      for (int j = 0; j < n; ++j) {
        digits[i] += (A[j] >> i) & 1;
      }
    }
    int  res = 0;
    for (int i = 0; i < 32; ++i) {
      res += (digits[i] % 2) << i;
    }
    return res;
  }
}

// *
class Solution2 {
public:
  int singleNumber(int A[], int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans ^= A[i];
    }
    return ans;
  }
};


int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 34};
  return 0;
}
