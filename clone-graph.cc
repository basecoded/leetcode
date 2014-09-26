/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
  public:
    map<UndirectedGraphNode*, UndirectedGraphNode*> copied;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      copied.clear();
      return copy(node);
    }

    UndirectedGraphNode* copy(UndirectedGraphNode* node) {
      if(node == NULL)
        return NULL;
      if(copied.find(node) != copied.end())
        return copied[node];
      UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
      copied[node] = new_node;
      for(auto n : node->neighbors)
        new_node->neighbors.push_back(copy(n));
      return new_node;
    }
};
