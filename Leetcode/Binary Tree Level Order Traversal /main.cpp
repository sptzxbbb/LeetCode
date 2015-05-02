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
  vector<vector<int> > levelOrder(TreeNode *root) {
    queue<TreeNode*> line;
    vector<vector<int> > ans;
    vector<int> temp;
    if (!root) return ans;

    line.push(root);
    line.push(NULL);
    while (!line.empty()) {
	// indicate a level ends
      if (NULL == line.front()) { 
        ans.push_back(temp);
        temp.clear();
        line.pop();
        if (!line.empty()) line.push(NULL);
      } else if (NULL != line.front()) {
	  // add its child node into next level
        temp.push_back(line.front()->val);
        if (line.front()->left)
          line.push(line.front()->left);
        if (line.front()->right)
          line.push(line.front()->right);
        line.pop();
      }
    }
    return ans;
  }
};
 
int main(int argc, char *argv[]) {
  
  return 0;
}

