# 322. 零钱兑换

- 算法分类：动态规划、完全背包。
- 数据结构：一维状态数组。
- 对应代码：[322_coin_change.cpp](./322_coin_change.cpp)。
- 掌握状态：最少数量动态规划模板。

## 背诵答案

```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
```

## 背诵口诀

> `dp[i]` 是凑出 `i` 的最少硬币数；
> 枚举最后使用的硬币；
> 去掉这枚硬币，再加一个。

如果凑出金额 `i` 的最后一枚硬币是 `coin`，那么前面的金额是 `i - coin`：

```cpp
dp[i] = min(dp[i], dp[i - coin] + 1);
```

`dp[0] = 0` 表示凑出金额 `0` 不需要硬币。

## 为什么初始值是 `amount + 1`

如果存在答案，最多使用 `amount` 枚面值为 `1` 的硬币。因此 `amount + 1` 可以作为“不可能”的哨兵值，同时执行 `+1` 时不会溢出。

最终若 `dp[amount] > amount`，说明没有任何组合能凑出目标金额，返回 `-1`。

## 易错点

- `dp[0]` 必须初始化为 `0`。
- 只有 `coin <= i` 时才能访问 `dp[i - coin]`。
- 每种硬币可以无限次使用，因此这是完全背包问题。
- 不可达状态最终返回 `-1`，不是返回哨兵值。
- 本题与第 279 题模板相同，只是候选数字从完全平方数变成了硬币面值。

设硬币种类数为 `n`，时间复杂度为 `O(amount * n)`，空间复杂度为 `O(amount)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/322_coin_change.cpp -o build/322
./build/322
```
