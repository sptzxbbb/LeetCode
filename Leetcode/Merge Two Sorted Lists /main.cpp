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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* index1 = l1, *index2 = l2, *s, *head;
    if (!l1) return l2;
    if (!l2) return l1;
    // set the head pointer to the smaller one
    if (index1->val > index2->val) {
      s = index2;
      index2 = index2->next;
    } else {
      s = index1;
      index1 = index1->next;
    }
    head = s;
    // merge sort
    while (index1 && index2) {
      if (index1->val < index2->val) {
        s->next = index1;
        s = s->next;
        index1 = index1->next;
      } else {
        s->next = index2;
        s = s->next;
        index2 = index2->next;
      }
    }
    // if one of lists reach ends
    if (!index1) s->next = index2;
    else s->next = index1;
    return head;
  }
};
