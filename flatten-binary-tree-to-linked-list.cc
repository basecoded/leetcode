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
    void flatten(TreeNode *root) {
      if (root == NULL)
        return;
      flatten(root->left);
      flatten(root->right);
      TreeNode* last = root->left;
      while (last && last->right)
        last = last->right;
      if (last) {
        TreeNode* tmp = root->right;
        root->right = root->left;
        last->right = tmp;
        root->left = NULL;
      }
    }
};
