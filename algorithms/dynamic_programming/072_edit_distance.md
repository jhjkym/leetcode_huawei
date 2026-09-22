# 72. 编辑距离

## 最优背诵代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j],
                                    dp[i][j - 1],
                                    dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n];
    }
};
```

## 状态含义

`dp[i][j]` 表示：把 `word1` 的前 `i` 个字符转换成 `word2` 的前 `j` 个字符，最少需要多少次操作。

## 初始化

```cpp
dp[i][0] = i;  // 变成空串，需要删除 i 次
dp[0][j] = j;  // 空串变成长为 j 的串，需要插入 j 次
```

## 状态转移

如果当前字符相同，不需要操作，直接继承左上角：

```cpp
dp[i][j] = dp[i - 1][j - 1];
```

如果不同，从三种操作中选择次数最少的，再加本次操作：

- `dp[i - 1][j]`：删除。
- `dp[i][j - 1]`：插入。
- `dp[i - 1][j - 1]`：替换。

```cpp
dp[i][j] = min({删除, 插入, 替换}) + 1;
```

## 背诵口诀

> 首行首列填下标；相同抄左上，不同取上、左、左上的最小值再加一。

## 复杂度

- 时间复杂度：`O(m × n)`
- 空间复杂度：`O(m × n)`

二维版本不是空间最省的版本，但含义清楚、最适合稳定默写。
