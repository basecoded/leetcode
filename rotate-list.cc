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
    ListNode *rotateRight(ListNode *head, int k) {
      if (head == NULL || head->next == NULL)
        return head;
      int len = 0;
      ListNode* p = head;
      while (p) {
        len++;
        p = p->next;
      }
      k %= len;
      if (k == 0)
        return head;
      p = head;
      ListNode *q = p;
      while (k--) {
        q = q->next;
      }
      while (q->next) {
        p = p->next;
        q = q->next;
      }
      ListNode* new_head = p->next;
      q->next = head;
      p->next = NULL;
      return new_head;
    }
};
