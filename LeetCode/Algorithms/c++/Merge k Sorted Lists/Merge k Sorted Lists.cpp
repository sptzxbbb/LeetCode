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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (0 == size) {
            return NULL;
        }
        while (size > 1) {
            int k = (size + 1) / 2;
            for (int i = 0; i < size / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            size = k;
        }
        return lists[0];
    }
    ListNode *mergeTwoLists(ListNode *head1, ListNode*head2) {
        ListNode node(0), *res = &node;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                res->next = head1;
                head1 = head1->next;
            } else {
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
        if (head1) {
            res->next = head1;
        } else if (head2) {
            res->next = head2;
        }
        return node.next;
    }
};

