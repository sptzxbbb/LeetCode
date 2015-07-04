#include "iostream"
using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int pos = 1, length = 0;
    // nonempty array, at least one element
    if (n) ++length;
    for (int i = 1; i < n; ++i) {
	//  distinct element detected
      if (A[i - 1] != A[i]) {
	  // put it in A[pos].
        A[pos++] = A[i];
        ++length;
      }
    }
    return length;
  }
};

int main(int argc, char *argv[]) {
  int arr[] = {1, 1, 1, 2, 2, 4, 5};
  Solution ans;
  cout << ans.removeDuplicates(arr, 7) << endl;
  return 0;
}
