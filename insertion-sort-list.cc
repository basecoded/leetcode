class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
      ListNode d(INT_MIN);
      for (ListNode* cur = head; cur;) {
        ListNode* tmp = cur->next;
        ListNode* pos = findPos(&d, cur);
        cur->next = pos->next;
        pos->next = cur;
        cur = tmp;
      }
      return d.next;
    }

    ListNode* findPos(ListNode* head, ListNode* target) {
      ListNode* p = head;
      while (p->next && p->next->val < target->val)
        p = p->next;
      return p;
    }
};
