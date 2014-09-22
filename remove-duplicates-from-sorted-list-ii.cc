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
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode dummy(-1);
      ListNode* p = &dummy;
      ListNode *pre = head, *cur = head;
      while (cur) {
        while (cur && cur->val == pre->val)
          cur = cur->next;
        if (pre->next == cur) {
          p->next = pre;
          p = p->next;
        }
        pre = cur;
      }
      p->next = NULL;
      return dummy.next;
    }
};
