/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
      int len = 0;
      ListNode* p = head;
      while (p) {
        len++;
        p = p->next;
      }
      return build(head, 0, len - 1);
    }

    TreeNode* build(ListNode*& head, int start, int end) {
      if (start > end)
        return NULL;
      int mid = start + (end - start) / 2;
      TreeNode* l_child = build(head, start, mid - 1);
      TreeNode* root = new TreeNode(head->val);
      head = head->next;
      root->left = l_child;
      root->right = build(head, mid + 1, end);
      return root;
    }
};
