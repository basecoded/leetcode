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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      ListNode dummy(0);
      ListNode* p = &dummy;
      while (l1 || l2) {
        int val1 = l1 == NULL ? INT_MAX : l1->val;
        int val2 = l2 == NULL ? INT_MAX : l2->val;
        if (val1 < val2) {
          p->next = l1;
          l1 = l1->next;
        } else {
          p->next = l2;
          l2 = l2->next;
        }
        p = p->next;
      }
      return dummy.next;
    }
};
