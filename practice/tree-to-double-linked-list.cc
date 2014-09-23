// Recursion
void InorderTraversal(TreeNode* root, TreeNode*& pre) {
  if (root == NULL)
    return;
  InorderTraversal(root->left, pre);
  if (pre) {
    pre->right = root;
    root->left = pre;
  }
  pre = root;
  InorderTraversal(root->right, pre);
}

// Iterative
TreeNode* Inorder(TreeNode* root) {
  TreeNode* head = NULL;
  TreeNode* p = root, *pre = NULL;
  while (p && p->left) {
    p = p->left;
  }
  head = p;
  p = root;
  stack<TreeNode*> stk;
  while (p || !stk.empty()) {
    if (p) {
      stk.push(p);
      p = p->left;
    } else {
      p = stk.top();
      cout << p->val << endl;
      stk.pop();
      if (pre) {
        pre->right = p;
        p->left = pre;
      }
      pre = p;
      p = p->right;
    }
  }
  return head;
}
