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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
      queue<TreeNode*> current, next;
      vector<vector<int>> result;
      if (root == NULL)
        return result;
      current.push(root);
      bool is_reverse = false;
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
        if (is_reverse)
          reverse(tmp.begin(), tmp.end());
        result.push_back(tmp);
        is_reverse = !is_reverse;
        swap(current, next);
      }
      return result;
    }
};
