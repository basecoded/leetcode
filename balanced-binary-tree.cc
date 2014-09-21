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
    bool isBalanced(TreeNode *root) {
      if (getHeight(root) >= 0)
        return true;
      else
        return false;
    }

    int getHeight(TreeNode* root) {
      if (root == NULL)
        return 0;
      int l_height = getHeight(root->left);
      int r_height = getHeight(root->right);
      if (l_height < 0 || r_height < 0)
        return -1;
      if (l_height - r_height > 1 || r_height - l_height > 1)
        return -1;
      return max(l_height, r_height) + 1;
    }
};
