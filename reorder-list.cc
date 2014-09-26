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
    int getListLen(ListNode* head) {
      int len = 0;
      while(head) {
        head = head->next;
        len++;
      }
      return len;
    }
    ListNode* reverseList(ListNode* head) {
      if(head == NULL)
        return NULL;
      ListNode dummy(-1);
      ListNode* pre = &dummy;
      dummy.next = head;
      ListNode* p = head;
      ListNode* pnext = NULL;
      while(p) {
        pnext = p->next;
        p->next = pre;
        pre = p;
        p = pnext;
      }
      head->next = NULL;
      return pre;
    }
    void divideList(ListNode* head, int listLen, ListNode*& head1, ListNode*& head2) {
      int firstLen = (listLen + 1) / 2;
      head1 = head;
      ListNode* pHalf = head;
      for(int k = 1; k < firstLen; k++) {
        pHalf = pHalf->next;
      }
      head2 = pHalf->next;
      pHalf->next = NULL;
    }

    void mergeList(ListNode* head1, ListNode* head2) {
      ListNode dummy(-1);
      ListNode* pre = &dummy;
      while(head1 || head2) {
        pre->next = head1;
        head1 = head1->next;
        pre = pre->next;

        pre->next = head2;
        if(head2) {
          head2 = head2->next;
          pre = pre->next;
        }
      }
    }
    void reorderList(ListNode *head) {
      if(head == NULL)
        return;
      int len = getListLen(head);
      ListNode* head1 = NULL;
      ListNode* head2 = NULL;
      divideList(head, len, head1, head2);
      head2 = reverseList(head2);
      mergeList(head1, head2);
    }
};
