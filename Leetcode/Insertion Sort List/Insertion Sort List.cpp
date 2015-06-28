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
    ListNode* insertionSortList(ListNode* head) {
        if (NULL == head) {
            return head;
        }

        ListNode *sorted = head, *unsorted = head->next, *to_insert;
        head->next = NULL;

        ListNode* dump = new ListNode(1);
        dump->next = sorted;

        while (unsorted != NULL) {
            to_insert = unsorted;
            unsorted = unsorted->next;
            to_insert->next = NULL;

            ListNode* pre = dump, *cur = dump->next;
            while (cur != NULL && cur->val < to_insert->val ) {
                pre = cur;
                cur = cur->next;
            }
            to_insert->next = cur;
            pre->next = to_insert;
        }

        head = dump->next;
        delete dump;
        return head;
    }
};