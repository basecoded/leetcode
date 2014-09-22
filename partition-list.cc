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
    ListNode *partition(ListNode *head, int x) {
      ListNode d_small(-1), d_big(-1);
      ListNode* p_small = &d_small, *p_big = &d_big, *p = head;
      while (p) {
        if (p->val < x) {
          p_small->next = p;
          p_small = p_small->next;
        } else {
          p_big->next = p;
          p_big = p_big->next;
        }
        p = p->next;
      }
      p_big->next = NULL;
      p_small->next = d_big.next;
      return d_small.next;
    }
};
