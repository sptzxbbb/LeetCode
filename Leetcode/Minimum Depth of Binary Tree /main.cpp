#include "iostream"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    int l, r;
    // empty node
    if (!root) return 0;
    // two child node
    if (root->left && root->right) {
      l = minDepth(root->left);
      r = minDepth(root->right);
      return (l > r ? (r + 1) : (l + 1));
    } else if (!root->left && root->right)
	// only right child node
      return minDepth(root->right) + 1;
    else if (root->left && !root->right)
	// only left child node
      return minDepth(root->left) + 1;
    else
	// no child node
      return 1;
  }
};
 
int main(int argc, char *argv[]) {
  TreeNode a(1), b(2), c(3);
  a.left = &b;
  a.right = &c;
  Solution k;
  cout << k.minDepth(&a) << endl;
  return 0;
}
