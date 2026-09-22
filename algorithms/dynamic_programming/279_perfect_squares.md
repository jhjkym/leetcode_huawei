# 279. 完全平方数

- 算法分类：动态规划、完全背包。
- 数据结构：一维状态数组。
- 对应代码：[279_perfect_squares.cpp](./279_perfect_squares.cpp)。
- 掌握状态：最少数量动态规划模板。

## 背诵答案

```cpp
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
```

## 背诵口诀

> `dp[i]` 是组成 `i` 的最少数量；
> 枚举最后使用的平方数 `j*j`；
> 去掉它，再加一个。

假设组成 `i` 的最后一个完全平方数是 `j * j`，那么前面的部分是 `i - j * j`：

```cpp
dp[i] = min(dp[i], dp[i - j * j] + 1);
```

`dp[0] = 0` 表示组成 `0` 不需要任何数字，也是所有状态转移的起点。

## 易错点

- `dp` 初始值使用 `INT_MAX`，表示尚未找到方案。
- 内层条件是 `j * j <= i`。
- 状态来自更小的 `i - j * j`，所以 `i` 从小到大遍历。
- 每个平方数可以重复使用，因此这是完全背包问题。
- 任意正整数都能由若干个 `1` 组成，所以每个状态最终都有合法值。

外层遍历 `n` 个状态，内层最多遍历 `sqrt(n)` 个平方数，时间复杂度为 `O(n√n)`，空间复杂度为 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/279_perfect_squares.cpp -o build/279
./build/279
```
