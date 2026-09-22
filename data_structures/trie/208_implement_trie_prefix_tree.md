# 208. 实现 Trie（前缀树）

- 算法分类：前缀树、字符串查找。
- 数据结构：Trie 节点、26 位孩子指针数组。
- 对应代码：[208_implement_trie_prefix_tree.cpp](./208_implement_trie_prefix_tree.cpp)。
- 掌握状态：Trie 基础模板。

## 背诵答案

```cpp
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
            if (!node->children[index]) return nullptr;
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
            if (!node->children[index]) {
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};
```

## 背诵口诀

> 插入：没有就创建，最后标记结尾；
> 查单词：路径存在并且是结尾；
> 查前缀：路径存在即可。

每个节点包含：

```cpp
Node* children[26]{};
bool isEnd = false;
```

- `children[c - 'a']` 指向字符 `c` 的下一个节点；
- `isEnd` 表示是否有一个完整单词在当前节点结束。

`search` 和 `startsWith` 都先调用 `find` 检查路径，区别只有是否要求 `isEnd == true`。

## 易错点

- 插入完整单词后必须将最后节点的 `isEnd` 设为 `true`。
- 路径存在不代表单词存在，例如插入 `apple` 后，`app` 是前缀但还不是完整单词。
- `search` 要检查 `isEnd`，`startsWith` 不需要。
- 题目只包含小写英文字母，因此可以使用长度为 `26` 的数组。

设字符串长度为 `L`，`insert`、`search` 和 `startsWith` 的时间复杂度都是 `O(L)`。每个节点最多保存 26 个孩子指针。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 data_structures/trie/208_implement_trie_prefix_tree.cpp -o build/208
./build/208
```
