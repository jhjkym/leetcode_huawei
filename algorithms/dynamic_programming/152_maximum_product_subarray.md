# 152. 乘积最大子数组

- 算法分类：动态规划、滚动变量。
- 数据结构：数组、最大最小状态。
- 对应代码：[152_maximum_product_subarray.cpp](./152_maximum_product_subarray.cpp)。
- 掌握状态：最大最小乘积模板。

## 背诵答案

```cpp
int maxProduct(vector<int>& nums) {
    int maximum = nums[0];
    int minimum = nums[0];
    int ans = nums[0];

    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i] < 0) swap(maximum, minimum);

        maximum = max(nums[i], maximum * nums[i]);
        minimum = min(nums[i], minimum * nums[i]);
        ans = max(ans, maximum);
    }
    return ans;
}
```

## 背诵口诀

> 同时维护最大和最小；
> 遇到负数先交换；
> 要么接上前面，要么从当前重新开始。

`maximum` 和 `minimum` 分别表示以当前位置结尾的最大、最小乘积。必须同时维护最小值，因为负数乘以最小负数可能变成新的最大正数。

遇到负数时，原最大值乘负数会变小，原最小值乘负数会变大，因此先交换：

```cpp
if (nums[i] < 0) swap(maximum, minimum);
```

然后决定从当前数字重新开始，还是接到前面的连续子数组后面：

```cpp
maximum = max(nums[i], maximum * nums[i]);
minimum = min(nums[i], minimum * nums[i]);
```

## 易错点

- 不能只维护最大乘积，负负得正时需要之前的最小乘积。
- 遇到负数要在更新最大值和最小值之前交换。
- `maximum`、`minimum` 和 `ans` 都初始化为 `nums[0]`，以正确处理全负数组。
- 数字 `0` 会自然让状态从当前位置重新开始，不需要单独判断。

每个元素访问一次，时间复杂度为 `O(n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/dynamic_programming/152_maximum_product_subarray.cpp -o build/152
./build/152
```
