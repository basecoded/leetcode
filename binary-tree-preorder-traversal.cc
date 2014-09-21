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
    vector<int> preorderTraversal(TreeNode *root) {
      stack<TreeNode*> stk;
      vector<int> result;
      TreeNode* p = root;
      while (p || !stk.empty()) {
        if (p) {
          result.push_back(p->val);
          stk.push(p);
          p = p->left;
        } else {
          p = stk.top();
          stk.pop();
          p = p->right;
        }
      }
      return result;
    }
};
