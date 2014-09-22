/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Comp {
  bool operator()(const ListNode* a, const ListNode* b) {
    return a->val > b->val;
  }
};
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
      priority_queue<ListNode*, vector<ListNode*>, Comp> q;
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i])
          q.push(lists[i]);
      }
      ListNode dummy(0);
      ListNode* p = &dummy;
      while (!q.empty()) {
        ListNode* node = q.top();
        p->next = node;
        p = p->next;
        q.pop();
        if (node->next)
          q.push(node->next);
      }
      return dummy.next;
    }
};
