/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode*> node;
        while (head != NULL) {
            TreeNode* p = new TreeNode(head->val);
            node.push_back(p);
            head = head->next;
        }
        TreeNode* newHead = generate(node, 0, node.size() - 1);
        return newHead;
    }
    TreeNode* generate(vector<TreeNode*>& node, int start, int end) {
        if (start > end) {
            return NULL;
        } else if (start == end) {
            return node[start];
        } else {
            int mid = (start + end) / 2;
            node[mid]->left = generate(node, start, mid - 1);
            node[mid]->right = generate(node, mid + 1, end);
            return node[mid];
        }
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode *cur = head;
        while (cur) {
            ++length;
            cur = cur->next;
        }
        return generate(head, 0, length - 1);
    }
    TreeNode* generate(ListNode *& head, int start, int end) {
        if (start > end) {
            return NULL;
        } else {
            int mid = (start + end) / 2;
            TreeNode *left = generate(head, start, mid - 1);
            TreeNode *root = new TreeNode(head->val);
            head = head->next;
            TreeNode *right = generate(head, mid + 1, end);
            root->left = left;
            root->right = right;
            return root;
        }
    }
};