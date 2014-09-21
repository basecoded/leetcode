/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if (root == NULL)
        return;
      TreeLinkNode dummy(0);
      for (TreeLinkNode* cur = &dummy, *p = root; p; p = p->next) {
        if (p->left) {
          cur->next = p->left;
          cur = cur->next;
        }
        if (p->right) {
          cur->next = p->right;
          cur = cur->next;
        }
      }
      connect(dummy.next);
    }
};
