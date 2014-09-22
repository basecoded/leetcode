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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode d(-1);
      d.next = head;
      ListNode* pre = &d, *p = &d;
      int step = n - m + 1;
      while (step--)
        p = p->next;
      while (--m) {
        p = p->next;
        pre = pre->next;
      }
      ListNode* tail_head = p->next;
      ListNode* mid_tail = pre->next;
      p->next = NULL;
      pre->next = reverse(mid_tail);
      mid_tail->next = tail_head;
      return d.next;
    }

    ListNode* reverse(ListNode* head) {
      ListNode* cur = head, *pre = NULL;
      while (cur) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      return pre;
    }
};
