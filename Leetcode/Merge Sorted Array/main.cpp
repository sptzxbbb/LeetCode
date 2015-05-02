#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    if (n < 1) return;
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      A[k--] = A[i] > B[j] ? A[i--] : B[j--];
    }
    while (j >= 0) {
      A[k--] = B[j--];
    }
  }
};

int main(int argc, char *argv[]) {
  int a1[5] = {1}, a2[] = {2};
  Solution k;
  k.merge(a1, 1, a2, 1);
  for (int i = 0; i < 2; ++i) {
    cout << a1[i] << ' ';
  }
  cout << endl;
  return 0;
}
