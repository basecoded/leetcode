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
      for (TreeLinkNode* cur = root, *p = &dummy; cur != NULL; cur = cur->next) {
        if (cur->left) {
          p->next = cur->left;
          p = p->next;
        }
        if (cur->right) {
          p->next = cur->right;
          p = p->next;
        }
      }
      connect(dummy.next);
    }
};
