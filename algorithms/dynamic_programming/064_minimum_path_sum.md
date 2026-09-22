# 64. 最小路径和

## 最优背诵代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);

        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1];
    }
};
```

## 思路

每个格子只能从上方或左方到达，因此到达当前格子的最小路径和是：

```text
min(上方路径和, 左方路径和) + 当前格子的值
```

用一维数组 `dp` 保存当前行：

- 更新前的 `dp[j]` 表示上方路径和。
- 已经更新的 `dp[j - 1]` 表示左方路径和。

所以状态转移为：

```cpp
dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
```

第一行只能从左边到达，第一列只能从上边到达，因此分别累加初始化。

## 背诵口诀

> 首行向左累加，首列向上累加；中间取上左最小，再加当前值。

## 复杂度

- 时间复杂度：`O(m × n)`
- 空间复杂度：`O(n)`
