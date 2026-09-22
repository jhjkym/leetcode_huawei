#include <bits/stdc++.h>
using namespace std;

// 208. 实现 Trie（前缀树）
// 每个节点保存 26 个孩子指针和一个单词结尾标记。
class Trie {
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root = new Node();

    Node* find(const string& word) {
        Node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) return nullptr;
            node = node->children[index];
        }
        return node;
    }

public:
    Trie() = default;

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

int main() {
    Trie trie;
    vector<pair<bool, bool>> results;

    trie.insert("apple");
    results.push_back({trie.search("apple"), true});
    results.push_back({trie.search("app"), false});
    results.push_back({trie.startsWith("app"), true});

    trie.insert("app");
    results.push_back({trie.search("app"), true});
    results.push_back({trie.search("appl"), false});
    results.push_back({trie.startsWith("apple"), true});
    results.push_back({trie.startsWith("banana"), false});

    trie.insert("banana");
    results.push_back({trie.search("banana"), true});
    results.push_back({trie.startsWith("ban"), true});
    results.push_back({trie.search("ban"), false});

    size_t passed = 0;
    for (size_t i = 0; i < results.size(); ++i) {
        bool actual = results[i].first;
        bool expected = results[i].second;
        bool ok = actual == expected;
        passed += ok;
        cout << "用例 " << i + 1 << "：预期 = " << boolalpha << expected
             << "，实际 = " << actual << "，"
             << (ok ? "PASS" : "FAIL") << '\n';
    }

    cout << "\n通过：" << passed << '/' << results.size() << '\n';
    return passed == results.size() ? 0 : 1;
}
