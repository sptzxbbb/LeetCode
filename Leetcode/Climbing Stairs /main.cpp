#include "iostream"
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int s1 = 1, s2 = 2, s3, count = 2;
    if (1 == n || 0 == n) return 1;
    if (2 == n) return 2;
    while (count != n) {
      s3 = s1 + s2;
      s1 = s2;
      s2 = s3;
      ++count;
    }
    return s3;
  }
};

int main(int argc, char *argv[]) {
  Solution k;
  cout << k.climbStairs(4) << endl;
  
  return 0;
}
