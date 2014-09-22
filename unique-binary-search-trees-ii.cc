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
    vector<TreeNode *> generateTrees(int n) {
      return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
      vector<TreeNode*> v;
      if (start > end) {
        v.push_back(NULL);
        return v;
      }
      for (int i = start; i <= end; i++) {
        vector<TreeNode*> l = generate(start, i - 1);
        vector<TreeNode*> r = generate(i + 1, end);
        for (auto l_child : l) {
          for (auto r_child : r) {
            TreeNode* root = new TreeNode(i);
            root->left = l_child;
            root->right = r_child;
            v.push_back(root);
          }
        }
      }
      return v;
    }
};
