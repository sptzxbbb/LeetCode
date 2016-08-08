/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head) {
            return head;
        }
        ListNode *_head = new ListNode(-1);
        ListNode *pre = _head, *cur = head, *post;
        int duplicate;
          _head->next = cur;
        while (cur != NULL) {
            duplicate = cur->val;
            post = cur->next;
            // post duplicates
            if (post != NULL && post->val == duplicate) {
                ListNode* temp;
                while (post != NULL && post->val == duplicate) {
                    temp = post->next;
                    delete post;
                    post = temp;
                }
                delete cur;
                cur = post;
                pre->next = cur;
            } else {
                pre = cur;
                cur = post;
            }
        }
        return _head->next;
    }
};