#include <iostream>
#include <string>
#include <vector>

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

void AddNodeToVector(vector<TreeNode*>& v, TreeNode* node, int& c2) {
  cout << node->val << " ";
  if (node->left) {
    v.push_back(node->left);
    c2++;
  }
  if (node->right) {
    v.push_back(node->right);
    c2++;
  }
}

void LevelOrderTraversal(TreeNode* root) {
  if (root == NULL) return ;
  vector<TreeNode*> v;
  v.push_back(root);
  int start = 0, c1 = 1, c2 = 0;
  bool reverse = false;
  while (c1) {
    if (reverse == false) {
      for (int i = start; i < start + c1; i++) {
        AddNodeToVector(v, v[i], c2);
      }
    } else {
      for (int i = start + c1 - 1; i > start - 1; i--) {
        AddNodeToVector(v, v[i], c2);
      }
    }
    cout << endl;
    start += c1;
    c1 = c2;
    c2 = 0;
    reverse = !reverse;
  }
  return ;
}

int main() {
  string str = "731##4#5##8##";
  TreeNode* root = Serialize(str);
  LevelOrderTraversal(root);
  return 0;
}
