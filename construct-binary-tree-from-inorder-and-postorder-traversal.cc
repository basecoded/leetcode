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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int po_start, int po_end) {
      if (in_start > in_end || po_start > po_end)
        return NULL;
      int val = postorder[po_end];
      TreeNode* root = new TreeNode(val);
      int len = findPos(inorder, val) - in_start;
      root->left = buildTree(inorder, postorder, in_start, in_start + len - 1, po_start, po_start + len - 1);
      root->right = buildTree(inorder, postorder, in_start + len + 1, in_end, po_start + len, po_end - 1);
      return root;
    }

    int findPos(vector<int>& v, int val) {
      for (int i = 0; i < v.size(); i++)
        if (v[i] == val)
          return i;
    }
};
