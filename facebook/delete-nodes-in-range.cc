#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int a): val(a), left(NULL), right(NULL){}
};

TreeNode* Serialize(const string& str, int& i) {
  if (str[i] == '#')
    return NULL;
  TreeNode* node = new TreeNode(str[i] - '0');
  node->left = Serialize(str, ++i);
  node->right = Serialize(str, ++i);
  return node;
}

TreeNode* Serialize(const string& str) {
  int i = 0;
  return Serialize(str, i);
}

TreeNode* new_root = NULL;

void DeleteNodesInRangeHelper(TreeNode *root, TreeNode *parent,
                              int start, int end) {
  if (root == NULL)
    return;
  DeleteNodesInRangeHelper(root->left, root, start, end);
  DeleteNodesInRangeHelper(root->right, root, start, end);
  if (root->val < start) {
    if (parent) {
      if (parent->left == root)
        parent->left = root->right;
      else
        parent->right = root->right;
      new_root = parent;
    } else {
      new_root = root->right;
    }
    return;
  }
  if (root->val > end) {
    if (parent) {
      if (parent->left == root)
        parent->left = root->left;
      else
        parent->right = root->left;
      new_root = parent;
    } else {
      new_root = root->left;
    }
    return;
  }
}

TreeNode* DeleteNodesInRange(TreeNode *root, int start, int end) {
  TreeNode *parent = NULL;
  DeleteNodesInRangeHelper(root, parent, start, end);
  return new_root;
}

void print(TreeNode* root) {
  if (root == NULL)
    return;
  print(root->left);
  cout << root->val << endl;
  print(root->right);
}

int main() {
  string str = "21##3##";
  TreeNode* root = Serialize(str);
  root = DeleteNodesInRange(root, 3, 4);
  print(root);
  return 0;
}
