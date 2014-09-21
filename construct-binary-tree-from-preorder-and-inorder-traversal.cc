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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
      if (pre_start > pre_end || in_start > in_end)
        return NULL;
      int val = preorder[pre_start];
      TreeNode* root = new TreeNode(val);
      int len = findPos(inorder, val) - in_start;
      root->left = buildTree(preorder, inorder, pre_start + 1, pre_start + len, in_start, in_start + len - 1);
      root->right = buildTree(preorder, inorder, pre_start + len + 1, pre_end, in_start + len + 1, in_end);
      return root;
    }

    int findPos(vector<int>& v, int val) {
      for (int i = 0; i < v.size(); i++)
        if (v[i] == val)
          return i;
    }
};
