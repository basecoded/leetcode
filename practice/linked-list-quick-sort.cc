ListNode *sortList(ListNode *head) {
  if(head == NULL || head->next == NULL) return head;
  ListNode *tail = NULL;
  return quicksort(head, tail);
}

ListNode *quicksort(ListNode *head, ListNode*& tail) {
  if (head == NULL || head->next == NULL) {
    tail = head;
    return head;
  }
  ListNode d1(-1), d2(-1);
  ListNode* p_small = &d1, *p_big = &d2;
  ListNode *pivot = head, *p = head->next;
  while (p != NULL) {
    if (p->val < pivot->val) {
      p_small->next = p;
      p_small = p_small->next;
    } else {
      p_big->next = p;
      p_big = p_big->next;
    }
    p = p->next;
  }
  p_small->next = NULL;
  p_big->next = NULL;
  ListNode *t1 = NULL, *t2 = NULL;
  ListNode *h1 = quicksort(d1.next, t1);
  ListNode *h2 = quicksort(d2.next, t2);
  if (t1 != NULL) {
    t1->next = pivot;
  }
  pivot->next = h2;
  tail = t2;
  return h1 == NULL ? pivot : h1;
}
