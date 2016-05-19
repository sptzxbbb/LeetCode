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
    ListNode* sortList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortList(head);
        slow = sortList(slow);
        return MergeSort(fast, slow);
    }
    ListNode* MergeSort(ListNode* a, ListNode* b) {
        ListNode *head = new ListNode(-1), *cur;
        ListNode *p1 = a, *p2 = b;
        cur = head;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = (p1 == NULL ? p2 : p1);
        cur = head;
        head = head->next;
        delete cur;
        return head;
    }
};