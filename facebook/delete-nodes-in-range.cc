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

void DeleteNodesInRange(TreeNode *root, int start, int end) {
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL
      && root->val < start || root->val > end) {
    delete root;    
  }
  if (root->val > end) {
    DeleteNodesInRange(root->left, start, end);
  } else if (root->val < start) {
    DeleteNodesInRange(root->right, start, end);
  } else {
    DeleteNodesInRange(root->left, start, end);
    DeleteNodesInRange(root->right, start, end);
  }
}

int main() {
  string str = "731##54##6###";
  TreeNode* root = Serialize(str);
  DeleteNodesInRange(root, 
  return 0;
}
