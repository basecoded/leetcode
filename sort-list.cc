// Quick sort to sort linked list.

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
    ListNode *sort(ListNode* head, ListNode*& tail) {
      if (head == NULL || head->next == NULL) {
        tail = head;
        return head;
      }
      ListNode d1(0), d2(0), d3(0);
      ListNode *p1 = &d1, *p2 = &d2, *p3 = &d3;
      ListNode *d1_tail = NULL, *d2_tail = NULL, *d3_tail = NULL;
      int pivot = head->val;
      while (head) {
        if (head->val < pivot) {
          p1->next = head;
          p1 = p1->next;
        } else if (head->val > pivot) {
          p3->next = head;
          p3 = p3->next;
        } else {
          p2->next = head;
          p2 = p2->next;
          d2_tail = p2;
        }
        head = head->next;
      }
      p1->next = p2->next = p3->next = NULL;
      ListNode *d1_head = sort(d1.next, d1_tail);
      ListNode *d3_head = sort(d3.next, d3_tail);
      d2_tail->next = d3_head;
      tail = d3_tail ? d3_tail : d2_tail;
      if (d1_tail) {
        d1_tail->next = d2.next;
        return d1_head;
      } else {
        return d2.next;
      }
    }
    ListNode *sortList(ListNode *head) {
      ListNode *tail = NULL;
      return sort(head, tail);
    }
};
