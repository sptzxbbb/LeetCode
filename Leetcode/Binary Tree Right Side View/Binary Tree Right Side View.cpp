/**
 * Definition for a binary tree node.  struct TreeNode { int val;
 * TreeNode *left; TreeNode *right; TreeNode(int x) : val(x),
 * left(NULL), right(NULL) {} };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        // empty tree
        if (!root) {
            return view;
        }
        list<TreeNode*> layer;
        layer.push_back(NULL);
        layer.push_back(root);
        TreeNode* t;
        while (!layer.empty()) {
            // new layer, top() is NULL
            layer.pop_front();
            // the last layer
            if (layer.empty()) {
                break;
            } else {
                // the first one in right side
                t = layer.front();
                view.push_back(t->val);
                layer.push_back(NULL);
                while ((t = layer.front()) != NULL) {
                    if (t->right) {
                        layer.push_back(t->right);
                    }
                    if (t->left) {
                        layer.push_back(t->left);
                    }
                    layer.pop_front();
                }
            }
        }
        return view;
    }
};