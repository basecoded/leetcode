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
    int maxPathSum(TreeNode *root) {
      int max_sum = INT_MIN;
      maxSum(root, max_sum);
      return max_sum;
    }

    int maxSum(TreeNode* root, int& max_sum) {
      if(root == NULL)
        return 0;
      int left = maxSum(root->left, max_sum);
      int right = maxSum(root->right, max_sum);
      int sum  = root->val;
      if(left > 0)
        sum += left;
      if(right > 0)
        sum += right;
      max_sum = max(max_sum, sum);
      return max(left, right) > 0 ? max(left, right) + root->val : root->val;
    }
};
