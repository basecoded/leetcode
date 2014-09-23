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
    void recoverTree(TreeNode *root) {
      TreeNode *e1 = NULL, *e2 = NULL;
      TreeNode *pre = NULL;
      recoverTreeHelper(root, pre, e1, e2);
      if (e1 && e2) {
        swap(e1->val, e2->val);
      }
      return ;
    }

    void recoverTreeHelper(TreeNode* root, TreeNode*& pre,
        TreeNode*& e1, TreeNode*& e2) {
      if (root == NULL)
        return;
      recoverTreeHelper(root->left, pre, e1, e2);
      if (pre && pre->val > root->val) {
        e2 = root;
        if (e1 == NULL)
          e1 = pre;
      }
      pre = root;
      recoverTreeHelper(root->right, pre, e1, e2);
    }
};
