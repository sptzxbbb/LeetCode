#include "iostream"

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode* dumb = new ListNode(0), *p1, *p2;
    dumb->next = head;
    p1 = dumb;
    p2 = head;
    while (p2) {
      if (p2->next && p2->val == p2->next->val) {
        p1->next = p2->next;
        delete p2;
        p2 = p1->next;
      } else {
        p1 = p1->next;
        p2 = p2->next;
      }
    }
    head = dumb->next;
    delete dumb;
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode* n1 = new ListNode(1), *n2 = new ListNode(1), *n3 = new ListNode(1);
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;
  Solution k;
  k.deleteDuplicates(n1);
  cout << n3->next << endl;
  return 0;
}

