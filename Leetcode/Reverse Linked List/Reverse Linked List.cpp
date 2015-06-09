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
    ListNode* reverseList(ListNode* head) {
		ListNode *pre, *cur, *next;
        if (NULL == head) {
            return NULL;
        } else if (NULL == head->next) {
            return head;
        } else {
            pre = head;
            cur = pre->next;
            next = cur->next;
            // new tail
            pre->next = NULL;
            while (NULL != cur) {
                cur->next = pre;
                pre = cur;
                cur = next;
                if (NULL != next) {
                    next = next->next;
                }
            }
            return pre;
        }
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode* newHead = reverserList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

