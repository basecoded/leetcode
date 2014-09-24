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

TreeNode* DeleteNodesInRange(TreeNode *root, int start, int end) {
  if (root == NULL) return root;
  TreeNode* left = DeleteNodesInRange(root->left, start, end);
  TreeNode* right = DeleteNodesInRange(root->right, start, end);
  if (root->val < start || root->val > end) {
    TreeNode* tmp = root;
    if (root->left) {
      root = root->left;
    } else if (root->right) {
      root = root->right;
    } else {
      root = NULL;
    }
    delete tmp;
  } else {
    root->left = left;
    root->right = right;
  }
  return root;
}

void print(TreeNode* root) {
  if (root == NULL)
    return;
  print(root->left);
  cout << root->val << endl;
  print(root->right);
}

int main() {
  string str = "731##4#5###";
  TreeNode* root = Serialize(str);
  root = DeleteNodesInRange(root, 3, 4);
  print(root);
  return 0;
}
