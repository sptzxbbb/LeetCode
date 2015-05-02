#include "iostream"
#include "queue"
#include "vector"
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    queue<TreeNode*> line;
    vector<vector<int> > ans;
    vector<int> temp;
    if (!root) return ans;

    line.push(root);
    line.push(NULL);
    while (!line.empty()) {
      if (NULL == line.front()) {
        ans.push_back(temp);
        temp.clear();
        line.pop();
        if (!line.empty()) line.push(NULL);
      } else if (NULL != line.front()) {
        temp.push_back(line.front()->val);
        if (line.front()->left)
          line.push(line.front()->left);
        if (line.front()->right)
          line.push(line.front()->right);
        line.pop();
      }
    }
    
    for (int i = 0; i < ans.size() / 2; ++i) {
      swap(ans[i], ans[ans.size() - 1 - i]);
    }
    return ans;
  }
};
 
int main(int argc, char *argv[]) {
  
  return 0;
}

