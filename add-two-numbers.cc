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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode dummy(0);
      ListNode* p = &dummy;
      int carry = 0;
      while(l1 || l2) {
        int val1 = l1 == NULL ? 0 : l1->val;
        int val2 = l2 == NULL ? 0 : l2->val;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum %= 10;
        p->next = new ListNode(sum);
        p = p->next;
        if(l1)
          l1 = l1->next;
        if(l2)
          l2 = l2->next;
      }
      if(carry)
        p->next = new ListNode(1);
      return dummy.next;
    }
}
