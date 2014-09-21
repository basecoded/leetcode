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
    int sumNumbers(TreeNode *root) {
      return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode* root, int val) {
      if (root == NULL)
        return 0;
      if (root->left == NULL && root->right == NULL)
        return val * 10 + root->val;
      else
        return sumNumbers(root->left, val * 10 + root->val) + sumNumbers(root->right, val * 10 + root->val);
    }
};
