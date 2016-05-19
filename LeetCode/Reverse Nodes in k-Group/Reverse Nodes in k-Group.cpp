/**
 * Definition for singly-linked list.
 * strict ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (NULL == head) {
            return head;
        }
        ListNode* p = new ListNode(1);
        ListNode* pre = p, *tail = head;
        while (ifNextK(head, k)) {
            reverseSingle(head, tail, k);
            pre->next = head;
            pre = tail;
            head = tail->next;
        }
        if(p->next) head = p->next;
        delete p;
        return head;
    }
    void reverseSingle(ListNode*& head, ListNode*& tail, int k) {
        tail = head;
        if (k < 2) {
            return;
        }
        ListNode *pre = NULL, *cur = head, *next;
        for (int i = 0; i < k; i++) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        tail->next = next;
        return;
    }
    bool ifNextK(ListNode* head, int k) {

        for (int i = 0; i < k; i++) {
            if (head != NULL) {
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
};