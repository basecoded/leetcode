class Solution {
  public:
    vector<int> postorderTraversal(TreeNode *root) {
      stack<TreeNode*> stk;
      vector<int> result;
      TreeNode* node = root;
      while (!stk.empty() || node) {
        if (node) {
          result.push_back(node->val);
          stk.push(node->left);
          node = node->right;
        } else {
          node = stk.top();
          stk.pop();
        }
      }
      reverse(result.begin(), result.end());
      return result;
    }
};
