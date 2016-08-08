#include "iostream"
#include "vector"
using namespace std;

// combination
class Solution1 {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    for (int i = 0; i < numRows; ++i) {
      vector<int> temp;
      for (int j = 0; j <= i; ++j) {
        temp.push_back(combine(i, j));
      }
      ans.push_back(temp);
    }
    return ans;
  }
  
  int combine(int n, int m) {
    m = m < (n - m) ? m : (n - m);
    long long a1 = 1, a2 = 1;
    for (int i = n; i >= n - m + 1; --i) {
      a1 *= i;
    }
    for (int i = 1; i <= m; ++i) {
      a2 *= i;
    }
    return a1 / a2;
  }
};

// addition
class Solution {
public:
  vector<vector<int> > generate(int rowIndex) {
    vector<vector<int> > k;
    if (0 == rowIndex) return k;

    vector<int> ans;

    for (int i = 0; i < rowIndex; ++i) {  // 1..rowIndex level
	// increase length
      ans.push_back(0);
      for (int j = i; j >= 0; --j) {
        if (j == i || 0 == j) ans[j] = 1;
        else ans[j] = ans[j - 1] + ans[j];
      }
      k.push_back(ans);
    }
    return k;
  }
};

int main(int argc, char *argv[]) {
  Solution a;

  a.generate(1);
  
  return 0;
}
