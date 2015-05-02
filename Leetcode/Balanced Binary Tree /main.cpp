#include "cmath"
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
    bool isBalanced(TreeNode *root) {
	if (!root) return true;

	int l = height(root->left);
	int r = height(root->right);
	int diff = abs(l - r);
	if (isBalanced(root->left) &&
	    isBalanced(root->right) && 
	    diff < 2) {
	    return true;
	}    else  {
	    return false;
	}
    }

    int height(TreeNode *root) {
	if (root == NULL) return 0;
	int l = height(root->left);
	int r = height(root->right);
	return (l > r ? l + 1 : r + 1;
    }
};

int wqmain(int argc, char *argv[]) {
  
    return 0;
}
