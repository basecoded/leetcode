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
    TreeNode *sortedArrayToBST(vector<int> &num) {
      return build(num, 0, num.size() - 1);
    }

    TreeNode* build(vector<int>& num, int start, int end) {
      if (start > end)
        return NULL;
      int mid = start + (end - start) / 2;
      TreeNode* node = new TreeNode(num[mid]);
      node->left = build(num, start, mid - 1);
      node->right = build(num, mid + 1, end);
      return node;
    }
};
