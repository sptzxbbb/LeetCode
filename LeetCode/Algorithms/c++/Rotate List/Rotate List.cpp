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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int len = 0;
        ListNode* p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        k = k % len;
        if (0 == k) {
            return head;
        }

        p = head;
        int step = 1;
        while (step != len - k) {
            p = p->next;
            ++step;
        }
        // spilt into two lists;
        ListNode* newHead = p->next;
        p->next = NULL;
        p = newHead;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = head;
        return newHead;
    }
};