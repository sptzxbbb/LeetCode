/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int step1 = 0, step2 = 0, diff;
    ListNode *temp1 = headA, *temp2 = headB;

    if (headA == NULL || headB == NULL) return NULL;
    if (headA == headB) return headA;
    

    while (temp1) {
      ++step1;
      temp1 = temp1->next;
    }
    while (temp2) {
      ++step2;
      temp2 = temp2->next;
    }

    temp1 = headA;
    temp2 = headB;
    if (step1 > step2) {
      diff = step1 - step2;
      while (diff--) {
        temp1 = temp1->next;
      }
    } else {
      diff = step2 - step1;
      while (diff--) {
        temp2 = temp2->next;
      }
    }

    while (temp1) {
      if (temp1 == temp2) return temp1;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    return NULL;
  }
};

int main(int argc, char *argv[]) {
  
  return 0;
}
