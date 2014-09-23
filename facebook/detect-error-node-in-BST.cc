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

TreeNode* error = NULL;

void DetectNodeHelper(TreeNode* root, TreeNode*& pre) {
  if (error)
    return;
  if (root == NULL)
    return;
  DetectNodeHelper(root->left, pre);
  if (pre && pre->val > root->val) {
    error = pre;
    return;
  }
  pre = root;
  DetectNodeHelper(root->right, pre);
}

TreeNode* DetectNode(TreeNode* root) {
  if (root == NULL)
    return NULL;
  TreeNode* pre = NULL;
  DetectNodeHelper(root, pre);
  return error;
}

int main() {
  string str = "731##84##6###";
  TreeNode* root = Serialize(str);
  DetectNode(root);
  if (error)
    cout << error->val << endl;
  return 0;
}
