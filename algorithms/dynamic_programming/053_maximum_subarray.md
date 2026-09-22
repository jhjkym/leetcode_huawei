# 53. 最大子数组和

- 算法分类：动态规划、Kadane 算法。
- 数据结构：数组、滚动变量。
- 对应代码：[053_maximum_subarray.cpp](./053_maximum_subarray.cpp)。
- 掌握状态：动态规划入门模板。

## 背诵答案

```cpp
int maxSubArray(vector<int>& nums) {
    int sum = 0, ans = nums[0];
    for (int num : nums) {
        sum = max(num, sum + num);
        ans = max(ans, sum);
    }
    return ans;
}
```

## 背诵口诀

> 当前和：接上前面，还是重新开始。
> 最终答案：记录最大的当前和。

`sum` 表示以当前元素结尾的最大子数组和。到达 `num` 时只有两种选择：

1. 不要前面的子数组，从 `num` 重新开始；
2. 接在前面的子数组后面，得到 `sum + num`。

因此状态转移为：

```cpp
sum = max(num, sum + num);
```

`ans` 记录所有位置产生过的最大 `sum`。

## 易错点

- 子数组不能为空，所以 `ans` 初始化为 `nums[0]`，不能初始化为 `0`；`sum` 可以从 `0` 开始。
- 全是负数时，应返回最大的那个负数。
- `sum` 表示“必须以当前位置结尾”的答案，`ans` 才是整个数组的答案。

时间复杂度为 `O(n)`，空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/053_maximum_subarray.cpp -o build/053
./build/053
```
