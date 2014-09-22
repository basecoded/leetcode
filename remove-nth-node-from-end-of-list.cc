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
      ListNode dummy(0);
      dummy.next = head;
      ListNode* p = &dummy, *pre = &dummy;
      while (n--)
        pre = pre->next;
      while (pre->next) {
        pre = pre->next;
        p = p->next;
      }
      ListNode* tmp = p->next;
      p->next = p->next->next;
      delete tmp;
      return dummy.next;
    }
};
