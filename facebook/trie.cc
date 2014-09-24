#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode {
  public:
    bool is_word;
    unordered_map<char, TrieNode*> letters;
    TrieNode(bool is_word) : is_word(is_word) {}
};

class Trie {
  public:
    Trie() : root(new TrieNode(false)) {}
    bool Insert(const string& s) {
      TrieNode* p = root;
      for (const char& c : s) {
        if (p->letters.find(c) == p->letters.end())
          p->letters[c] = new TrieNode(false);
        p = p->letters[c];
      }
      if (p->is_word) {
        return false;
      } else {
        p->is_word = true;
        return true;
      }
    }

    void Search(const string& word) {
      string str;
      dfs(str, root, word, 0);
      return;
    }

  private:
    TrieNode* root;
    void dfs(string& str, TrieNode* root, const string& word, int start) {
      if (start == word.size() && root->is_word) {
        cout << str << endl;
        return;
      }
      char ch = word[start];
      if (ch != '.') {
        if (root->letters.find(ch) != root->letters.end()) {
          str.push_back(ch);
          dfs(str, root->letters[ch], word, start + 1);
          str.pop_back();
        }
      } else { // ch == '.'
        for (const auto letter : root->letters) {
          str.push_back(letter.first);
          dfs(str, letter.second, word, start + 1);
          str.pop_back();
        }
      }
    }
};

int main() {
  vector<string> v{"cati", "cota", "cutb", "cur", "cuthair"};
  Trie trie;
  for (const auto n : v)
    trie.Insert(n);
  trie.Search("c.t.");
  return 0;
}
