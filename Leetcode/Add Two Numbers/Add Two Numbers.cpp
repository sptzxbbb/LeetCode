#include <iostream>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long num1 = 0, num2 = 0;
        ListNode *p1 = l1, *p2 = l2;
        stack<int> digit1, digit2;
        while (p1 != NULL) {
            digit1.push(p1->val);
            p1 = p1->next;
        }
        while (!digit1.empty()) {
            num1 = num1 * 10 + digit1.top();
            digit1.pop();
        }

        while (p2 != NULL) {
            digit2.push(p2->val);
            p2 = p2->next;
        }
        while (!digit2.empty()) {
            num2 = num2 * 10 + digit2.top();
            digit2.pop();
        }
        long ans = num1 + num2, remainder = 0;
        ListNode* head = NULL, *last = head, *temp;
        if (ans != 0) {
            while (ans != 0) {
                remainder = ans % 10;
                ans /= 10;
                if (head) {
                    temp = new ListNode(remainder);
                    last->next = temp;
                    last = temp;
                } else {
                    head = new ListNode(remainder);
                    last = head;
                }
            }
        } else {
            head = new ListNode(0);
        }
        return head;
    }
};

int main(int argc, char *argv[]) {
    ListNode a1(9), b1(1), b2(9), b3(9), ;
    b1.next = &b2;
    b2.next = &b3;
    Solution k;
    k.addTwoNumbers(&a1, &b1);
    return 0;
}
