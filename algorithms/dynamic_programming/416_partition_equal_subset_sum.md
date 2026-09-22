# 416. 分割等和子集

## 题目思路

如果数组能分成两个元素和相等的子集，那么每个子集的元素和一定是数组总和的一半。

- 总和是奇数：不可能平分，直接返回 `false`。
- 总和是偶数：问题变成能否从数组中选出若干数字，使它们的和等于 `sum / 2`。

这就是一个标准的 0/1 背包问题。

## 最优背诵代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
```

## 状态含义

`dp[j]` 表示：能否从已经遍历过的数字中，选出若干个数字组成和 `j`。

初始化 `dp[0] = true`，表示不选任何数字就能组成和 `0`。

遇到数字 `num` 时：

```cpp
dp[j] = dp[j] || dp[j - num];
```

含义是：

- 原来就能组成 `j`；或者
- 原来能组成 `j - num`，现在再选择 `num`。

## 为什么倒序遍历

每个数字只能使用一次，所以容量 `j` 必须从大到小遍历。

如果从小到大遍历，本轮刚更新的状态还会继续参与计算，相当于同一个数字可以被重复使用。

## 背诵口诀

> 总和奇数直接退，目标取一半；每个数只能用一次，容量从大到小。

## 复杂度

- 时间复杂度：`O(n × target)`
- 空间复杂度：`O(target)`
