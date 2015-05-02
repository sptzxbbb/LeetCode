#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);
    ans[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {  // row
      for (int j = i; j >= 0; --j) {
        if (j == i || j == 0) ans[j] = 1;
        else ans[j] = ans[j - 1] + ans[j];
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution k;
  vector<int> a;
  a = k.getRow(21);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
