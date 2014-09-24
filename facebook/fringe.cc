#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  vector<TreeNode*> children;
  TreeNode(int a) : val(a){}
};

int GetNextLeaf(stack<TreeNode*>& stk) {
  while (stk.size()) {
    TreeNode* p = stk.top();
    stk.pop();
    if (p->children.size() == 0) {
      return p->val;
    } else {
      for (const auto child : p->children)
        stk.push(child);
    }
  }
  return INT_MAX;
}

bool CompareFringe(TreeNode* root1, TreeNode* root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;
  stack<TreeNode*> stk1, stk2;
  stk1.push(root1);
  stk2.push(root2);
  while (stk1.size() || stk2.size()) {
    int leaf1 = GetNextLeaf(stk1);
    int leaf2 = GetNextLeaf(stk2);
    if (leaf1 != leaf2)
      return false;
    cout << leaf1 << endl;
  }
  return true;
}

int main() {
  TreeNode* root1 = new TreeNode(1);
  TreeNode* root1_1 = new TreeNode(2);
  TreeNode* root1_2 = new TreeNode(3);
  TreeNode* root1_3 = new TreeNode(4);
  root1->children.push_back(root1_1);
  root1->children.push_back(root1_2);
  root1->children.push_back(root1_3);

  TreeNode* root2 = new TreeNode(1);
  TreeNode* root2_1= new TreeNode(5);
  TreeNode* root2_2= new TreeNode(3);
  TreeNode* root2_3= new TreeNode(6);
  root2->children.push_back(root2_1);
  root2->children.push_back(root2_2);
  root2->children.push_back(root2_3);
  TreeNode* root2_1_1= new TreeNode(2);
  TreeNode* root2_3_1= new TreeNode(4);
  root2_1->children.push_back(root2_1_1);
  root2_3->children.push_back(root2_3_1);
  cout << CompareFringe(root1, root2) << endl;
  return 0;
}
