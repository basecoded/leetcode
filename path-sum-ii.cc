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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      vector<vector<int>> result;
      vector<int> path;
      dfs(result, path, root, sum);
      return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int gap) {
      if (root == NULL)
        return;
      path.push_back(root->val);
      if (root->left == NULL && root->right == NULL && root->val == gap) {
        result.push_back(path);
      }
      dfs(result, path, root->left, gap - root->val);
      dfs(result, path, root->right, gap - root->val);
      path.pop_back();
    }
};
