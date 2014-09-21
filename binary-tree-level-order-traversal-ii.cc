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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
      vector<vector<int>> result;
      queue<TreeNode*> current, next;
      if (root == NULL)
        return result;
      current.push(root);
      while (!current.empty()) {
        vector<int> tmp;
        while (!current.empty()) {
          TreeNode* p = current.front();
          current.pop();
          tmp.push_back(p->val);
          if (p->left)
            next.push(p->left);
          if (p->right)
            next.push(p->right);
        }
        result.push_back(tmp);
        swap(current, next);
      }
      reverse(result.begin(), result.end());
      return result;
    }
};
