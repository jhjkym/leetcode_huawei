# 41. 缺失的第一个正数

- 算法分类：原地哈希、交换归位。
- 数据结构：数组。
- 对应代码：[041_first_missing_positive.cpp](./041_first_missing_positive.cpp)。
- 掌握状态：原地哈希模板。

## 背诵答案

```cpp
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        while (nums[i] >= 1 && nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}
```

## 背诵口诀

> 数字 `x` 应该放在下标 `x - 1`。
> 先把数字归位，再找第一个错位。

长度为 `n` 的数组，答案一定在 `[1, n + 1]` 中。因此只需处理 `[1, n]` 范围内的数字，把每个数字 `x` 交换到 `nums[x - 1]`。

归位完成后：

- 如果 `nums[i] != i + 1`，缺失的第一个正数就是 `i + 1`；
- 如果所有位置都正确，说明 `1` 到 `n` 都存在，答案是 `n + 1`。

## `while` 的三个条件

```cpp
nums[i] >= 1                  // 是正数
nums[i] <= n                  // 在需要处理的范围内
nums[nums[i] - 1] != nums[i] // 目标位置没有相同数字
```

第三个条件用于处理重复数字，否则两个相同数字可能被无限交换。

## 易错点

- 使用 `while` 而不是 `if`，因为交换过来的新数字可能也需要继续归位。
- 数字 `x` 对应的下标是 `x - 1`，不是 `x`。
- 必须先判断 `nums[i]` 在 `[1, n]` 内，才能访问 `nums[nums[i] - 1]`。
- 算法会修改原数组，这是题目允许的。

每个数字最多被归位一次，时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/hash_table/041_first_missing_positive.cpp -o build/041
./build/041
```
