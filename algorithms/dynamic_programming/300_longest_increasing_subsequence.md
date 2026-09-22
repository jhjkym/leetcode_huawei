# 300. 最长递增子序列

- 算法分类：动态规划。
- 数据结构：状态数组 `dp`。
- 对应代码：[300_longest_increasing_subsequence.cpp](./300_longest_increasing_subsequence.cpp)。
- 掌握状态：序列动态规划模板。

## 背诵答案

```cpp
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

`dp[i]` 表示以 `nums[i]` 结尾的最长递增子序列长度。遍历 `i` 时，再检查前面的每个 `j`：如果 `nums[i] > nums[j]`，说明 `nums[i]` 可以接到以 `nums[j]` 结尾的序列后面，于是用 `dp[j] + 1` 更新 `dp[i]`。

## 背诵口诀

> `dp[i]` 是以 `nums[i]` 结尾的最长长度；
> 枚举前面的 `j`；
> 当前值更大，就从 `dp[j] + 1` 转移。

所有 `dp[i]` 算完后，答案是其中的最大值。初始化为 `1` 是因为每个元素本身都能构成长度为 `1` 的子序列。

## 易错点

- `dp[i]` 必须以 `nums[i]` 结尾，不是前 `i` 个元素的全局答案。
- 严格递增使用 `nums[i] > nums[j]`，相等不能连接。
- 每个 `dp[i]` 初始化为 `1`。
- 最终答案是所有 `dp[i]` 的最大值，而不一定是 `dp[n - 1]`。
- 本地代码额外处理空数组并返回 `0`。

## 复杂度

两层循环分别枚举结尾位置和前驱位置，时间复杂度 `O(n²)`，空间复杂度 `O(n)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/300_longest_increasing_subsequence.cpp -o build/300
./build/300
```
