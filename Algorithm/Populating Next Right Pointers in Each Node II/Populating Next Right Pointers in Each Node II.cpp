/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect1(TreeLinkNode* root) {
        list<TreeLinkNode*> l;
        if (root) {
            l.push_back(root);
            l.push_back(NULL);
        }
        TreeLinkNode* cur;
        while (l.size()) {
            cur = l.front();
            l.pop_front();
            // node
            if (cur) {
                cur->next = l.front();

                if (cur->left) {
                    l.push_back(cur->left);
                }
                if (cur->right) {
                    l.push_back(cur->right);
                }
            } else {
                // end of a level
                if (l.size()) {
                    l.push_back(NULL);
                }
            }
        }
        return;
    }

    void connect2(TreeLinkNode *root) {
        if (NULL == root) {
            return;
        }
        TreeLinkNode *p = root->next;
        while (p != NULL) {
            if (p->left != NULL) {
                p = p->left;
                break;
            }
            if (p->right != NULL) {
                p = p->right;
                break;
            }
            p = p->next;
        }

        if (root->right) {
            root->right->next = p;
        }
        if (root->left) {
            root->left->next = (root->right) ? root->right : p ;
        }

        connect(root->right);
        connect(root->left);
    }
};






















