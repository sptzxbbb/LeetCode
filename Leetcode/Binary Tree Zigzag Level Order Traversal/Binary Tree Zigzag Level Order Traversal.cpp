/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
<<<<<<< HEAD
enum direction {
    left_to_right,
    right_to_left
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> cur;
        vector<vector<int> > res;
        if (NULL == root) {
            return res;
        }

        direction dir = left_to_right;
        cur.push(root);
        while (!cur.empty()) {
            vector<int> floor;
            stack<TreeNode*> next;
            if (dir == left_to_right) {
                while (!cur.empty()) {
                    if (cur.top()->left) {
                        next.push(cur.top()->left);
                    }
                    if (cur.top()->right) {
                        next.push(cur.top()->right);
                    }
                    floor.push_back(cur.top()->val);
                    cur.pop();
                }
                dir = right_to_left;
            } else {
                while (!cur.empty()) {
                    if (cur.top()->right) {
                        next.push(cur.top()->right);
                    }
                    if (cur.top()->left) {
                        next.push(cur.top()->left);
                    }
                    floor.push_back(cur.top()->val);
                    cur.pop();
                }
                dir = left_to_right;
            }
            cur = next;
            res.push_back(floor);
        }
        return res;
=======
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        
>>>>>>> 9d56d4d13e882843b1c206d72fd7aaa90d7c24e2
    }
};