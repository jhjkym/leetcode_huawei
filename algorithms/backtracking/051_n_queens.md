# 51. N 皇后

- 算法分类：回溯、剪枝。
- 数据结构：棋盘、列与对角线占用数组。
- 对应代码：[051_n_queens.cpp](./051_n_queens.cpp)。
- 掌握状态：棋盘回溯模板。

## 背诵答案

```cpp
class Solution {
    int n;
    vector<string> board;
    vector<bool> columns, diagonal1, diagonal2;
    vector<vector<string>> ans;

public:
    vector<vector<string>> solveNQueens(int size) {
        n = size;
        board.assign(n, string(n, '.'));
        columns.assign(n, false);
        diagonal1.assign(2 * n - 1, false);
        diagonal2.assign(2 * n - 1, false);
        ans.clear();
        backtrack(0);
        return ans;
    }

private:
    void backtrack(int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (columns[col] || diagonal1[d1] || diagonal2[d2]) continue;

            board[row][col] = 'Q';
            columns[col] = diagonal1[d1] = diagonal2[d2] = true;
            backtrack(row + 1);
            board[row][col] = '.';
            columns[col] = diagonal1[d1] = diagonal2[d2] = false;
        }
    }
};
```

## 背诵口诀

> 一行只放一个；
> 检查列、左斜线、右斜线；
> 放置、递归、撤销。

逐行递归已经保证每行只有一个皇后，因此只需检查三种冲突：

```cpp
columns[col]             // 同一列
diagonal1[row-col+n-1]   // 主对角线
diagonal2[row+col]       // 副对角线
```

同一条主对角线上的 `row - col` 相同。因为它可能为负数，所以加上 `n - 1`。同一条副对角线上的 `row + col` 相同。两种对角线都共有 `2 * n - 1` 条。

## 易错点

- 到达 `row == n` 时，说明所有行都成功放置了皇后，应收集棋盘。
- 三个位置都未被占用时才能放置。
- 回溯时既要恢复棋盘，也要恢复三组占用标记。
- 主对角线下标是 `row - col + n - 1`，副对角线下标是 `row + col`。
- 每次入口调用都要重新初始化成员变量并清空答案。

时间复杂度通常写作 `O(n!)`，额外空间复杂度为 `O(n^2)`，主要用于保存棋盘；递归深度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/backtracking/051_n_queens.cpp -o build/051
./build/051
```
