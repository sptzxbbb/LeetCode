#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";

    string prefix = strs[0], temp;
    // length of prefix
    int length = strs[0].size();

    for (int i = 1; i < strs.size(); ++i) {
      length = min(length, (int)strs[i].size());
      temp = "";
      // temp is the new prefix
      for (int j = 0; j < length; ++j) {
        if (prefix[j] == strs[i][j]) temp += prefix[j];
        else break;
      }
      prefix = temp;
    }
    return prefix;
  }
};

int main(int argc, char *argv[]) {
  string s1 = "abc", s2 = "abcd", s3 = "cd";
  vector<string> arr;
  arr.push_back(s1);
  arr.push_back(s2);
  arr.push_back(s3);
  Solution a;
  cout << a.longestCommonPrefix(arr) << endl;
  return 0;
}
