//Sink Zero in Binary Tree. Swap zero value of a node with non-zero value of one of its descendants 
//so that no node with value zero could be parent of node with non-zero.
//题目：把二叉树中的值为0的节点尽量往下沉，保证所有值为0的节点绝不会有非0的子节点。

void SinkZeroHelper(TreeNode* root) {
  if (root == NULL)
    return;
  if (root->left != NULL && root->left->val != 0) {
    swap(root->val, root->left->val);
    SinkZeroHelper(root->left);
  } else if (root->right != NULL && root->right->val != 0) {
    swap(root->val, root->right->val);
    SinkZeroHelper(root->right);
  }
}

void SinkZero(TreeNode *root) {
  if (root == NULL)
    return ;
  SinkZero(root->left);
  SinkZero(root->right);
  if (root->val == 0)
    SinkZeroHelper(root);
  return;
}
