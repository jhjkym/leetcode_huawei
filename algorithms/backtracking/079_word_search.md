# 79. 单词搜索

- 算法分类：DFS、回溯。
- 数据结构：二维字符网格、递归栈。
- 对应代码：[079_word_search.cpp](./079_word_search.cpp)。
- 掌握状态：**不会，已提供答案模板，待复习背诵。**

## 背诵模板

从每个格子尝试作为起点。DFS 中先判断越界和字符是否匹配；匹配后把当前格标记为已使用，向上下左右递归寻找下一个字符。如果四个方向都失败，恢复当前字符。

```cpp
bool dfs(int x, int y, int index) {
    if (index == word.size()) return true;
    if (越界 || board[x][y] != word[index]) return false;
    char saved = board[x][y];
    board[x][y] = '#';
    for (四个方向) {
        if (dfs(下一格, index + 1)) return true;
    }
    board[x][y] = saved;
    return false;
}
```

**口诀：找到起点搜四方，匹配标记，失败恢复。**

## 易错点

- 同一个单元格不能重复使用，入路径时标记，递归失败时恢复。
- 只允许上下左右四个方向，不能斜着走。
- 找到完整单词后直接返回 `true`。
- 从每个格子都要尝试，因为起点未知。
- `board` 会被临时修改，所有失败分支必须恢复，否则会影响其他起点。

时间复杂度最坏为 `O(mn·4^L)`，`L` 为单词长度；递归和路径标记辅助空间为 `O(L)`（原地修改网格）。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/079_word_search.cpp -o build/079
./build/079
```
