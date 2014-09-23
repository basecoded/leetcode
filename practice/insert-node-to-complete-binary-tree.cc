int GetDepth(TreeNode* root, bool is_left) {
  int i = 0;
  while (root) {
    i++;
    if (is_left)
      root = root->left;
    else
      root = root->right;
  }
  return i;
}

  bool IsComplete(TreeNode* root) {
    if (root == NULL)
      return true;
    else
      return GetDepth(root, true) == GetDepth(root, false);
  }

TreeNode* InsertNodeToCompleteTree(TreeNode* root, TreeNode* node) {
  if (root == NULL) {
    return node;
  } else if (root->left == NULL) {
    root->left = node;
    return root;
  } else if (root->right == NULL) {
    root->right = node;
    return root;
  }
  if (GetDepth(root, true) == GetDepth(root, false)) {
    TreeNode* p = root;
    while (p->left)
      p = p->left;
    p->left = node;
    return root;
  } else {
    if (IsComplete(root->left))
      return InsertNodeToCompleteTree(root->right, node);
    else
      return InsertNodeToCompleteTree(root->left, node);
  }
}
