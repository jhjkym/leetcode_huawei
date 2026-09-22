# 1143. 最长公共子序列

## 最优背诵代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
```

## 状态含义

`dp[i][j]` 表示：`text1` 的前 `i` 个字符与 `text2` 的前 `j` 个字符，其最长公共子序列的长度。

数组多开一行一列，让空字符串对应的状态自然为 `0`，避免单独处理边界。

## 状态转移

当前两个字符相同，可以同时选入公共子序列：

```cpp
dp[i][j] = dp[i - 1][j - 1] + 1;
```

当前两个字符不同，它们不能同时作为公共子序列的末尾，因此分别舍弃一个字符，取较大值：

```cpp
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
```

注意：`dp` 的下标从 `1` 开始，而字符串下标从 `0` 开始，所以比较的是 `text1[i - 1]` 和 `text2[j - 1]`。

## 背诵口诀

> 状态表示两个前缀；字符相同左上加一，不同取上左最大。

## 复杂度

- 时间复杂度：`O(m × n)`
- 空间复杂度：`O(m × n)`

二维版本不是空间最省的版本，但状态最直观，更适合面试时稳定默写。
