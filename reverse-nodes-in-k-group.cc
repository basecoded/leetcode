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
    ListNode *reverseKGroup(ListNode *head, int k) {
      ListNode* next_group = head;
      for (int i = 0; i < k; i++) {
        if (next_group)
          next_group = next_group->next;
        else
          return head;
      }
      ListNode* new_head = reverse(head, next_group);
      head->next = reverseKGroup(next_group, k);
      return new_head;
    }

    ListNode* reverse(ListNode* head, ListNode* stop) {
      ListNode* cur = head, *pre = NULL;
      while (cur && cur != stop) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
      }
      return pre;
    }
};
