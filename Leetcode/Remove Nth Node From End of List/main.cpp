#include "vector"
#include "iostream"


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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    vector<ListNode*> arr;
    ListNode* temp = head;
    while (temp) {
      arr.push_back(temp);
      temp = temp->next;
    }

    int pos = arr.size() - n;
    temp = arr[pos];
    // remove the first node
    if (0 == pos) {
      head = head->next;
    } else {
      arr[pos - 1]->next = arr[pos]->next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  
  return 0;
}
