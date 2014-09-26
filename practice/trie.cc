#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
  public:
    bool is_string;
    unordered_map<char, shared_ptr<TrieNode>> l;
    TrieNode(bool is_word) : is_string(is_word) {}
};

class Trie {
  public:
    shared_ptr<TrieNode> root;
    Trie() : root(shared_ptr<TrieNode>(new TrieNode(false))) {}
    bool insert(const string& s) {
      shared_ptr<TrieNode> p = root;
      for (const char& c : s) {
        if (p->l.find(c) == p->l.end())
          p->l[c] = shared_ptr<TrieNode>(new TrieNode(false));
        p = p->l[c];
      }
      if (p->is_string) {
        return false;
      } else {
        p->is_string = true;
        return true;
      }
    }

    void WildCharSearch(const string& word, const string prefix,
                        shared_ptr<TrieNode> node) {
      string result;
      for (int i = 0; i < word.size(); i++) {
        if (word[i] != '.') {
          if (node->l.find(word[i]) != node->l.end()) {
            result.push_back(word[i]);
            node = node->l[word[i]];
          } else {
            return ;
          }
        } else { // word[i] == '.'
          for (const auto n : node->l)
            WildCharSearch(word.substr(i + 1, word.size() - i - 1), result + n.first, n.second);
        }
      }
      if (node->is_string)
        cout << prefix + result << endl;
      return;
    }
};

int main() {
  vector<string> v{"cati", "cota", "cutb", "cur", "cuthair"};
  Trie trie;
  for (const auto n : v)
    trie.insert(n);
  trie.WildCharSearch("c.t.", "", trie.root);
  return 0;
}
