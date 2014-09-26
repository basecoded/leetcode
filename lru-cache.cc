struct Node {
  int key;
  int value;
  Node* pre;
  Node* next;
  Node(int a, int b) : key(a), value(b), pre(NULL), next(NULL) {}
};

class LRUCache{
  public:
    int Capacity;
    Node* head, *tail;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
      Capacity = capacity;
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->pre = head;
    }

    int get(int key) {
      if (cache.find(key) == cache.end())
        return -1;
      Node* node = cache[key];
      node->pre->next = node->next;
      node->next->pre = node->pre;
      attach(node);
      return node->value;
    }

    void set(int key, int value) {
      if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->value = value;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        attach(node);
        return;
      }
      if (cache.size() == Capacity)
        dettach();
      Node* node = new Node(key, value);
      cache[key] = node;
      attach(node);
    }

    void attach(Node* node) {
      node->next = head->next;
      node->pre = head;
      head->next->pre = node;
      head->next = node;
    }

    void dettach() {
      Node* tmp = tail->pre;
      tmp->pre->next = tail;
      tail->pre = tmp->pre;
      cache.erase(tmp->key);
      delete tmp;
    }
};
