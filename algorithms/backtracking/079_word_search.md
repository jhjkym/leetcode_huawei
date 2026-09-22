# 79. 单词搜索

- 算法分类：DFS、回溯。
- 数据结构：二维字符网格、递归栈。
- 对应代码：[079_word_search.cpp](./079_word_search.cpp)。
- 掌握状态：网格回溯模板。

## 背诵模板

从每个格子尝试作为起点。`dfs(i, j, k)` 表示从格子 `(i, j)` 开始匹配单词的第 `k` 个字符。

先判断越界和字符是否匹配，匹配到最后一个字符就成功。否则标记当前格，向上下左右寻找下一个字符；保存搜索结果，恢复当前格，再返回结果。

```cpp
class Solution {
    int m = 0, n = 0, length = 0;

    bool dfs(vector<vector<char>>& board, const string& word,
             int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[k]) return false;
        if (k == length - 1) return true;

        char saved = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1);
        board[i][j] = saved;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        m = board.size();
        n = board[0].size();
        length = word.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
```

**口诀：每格试起点；越界不符退；末字匹配成；标记搜四向，恢复再返回。**

## 易错点

- 同一个单元格不能重复使用，入路径时用 `'#'` 标记；题目中的字符为字母，不会与标记冲突。
- 只允许上下左右四个方向，不能斜着走。
- 必须先确认当前字符匹配，再判断是否到达最后一个字符。
- 从每个格子都要尝试，因为起点未知。
- `||` 遇到成功方向就停止继续搜索。先把结果存入 `found`，恢复棋盘后再返回，成功和失败都会恢复现场。
- `board` 传引用以便标记和恢复，`word` 传常量引用，避免每次递归复制单词。

时间复杂度为 `O(mn·3^L)`，`m`、`n` 为网格行列数，`L` 为单词长度。第一步最多有四个方向，之后不能回到上一格，每步最多三个方向；递归栈辅助空间为 `O(L)`，路径直接在网格上标记。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/079_word_search.cpp -o build/079
./build/079
```

现有 16 个用例全部通过，同时验证了搜索结果正确、调用后棋盘恢复原样。
