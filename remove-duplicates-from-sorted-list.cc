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
      ListNode dummy(INT_MAX);
      ListNode* p = &dummy;
      while (head) {
        if (head->val != p->val) {
          p->next = head;
          p = p->next;
        }
        head = head->next;
      }
      p->next = NULL;
      return dummy.next;
    }
};
