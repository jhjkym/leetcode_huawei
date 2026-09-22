# 238. 除了自身以外数组的乘积

- 算法分类：前缀积、后缀积。
- 数据结构：数组、滚动变量。
- 对应代码：[238_product_of_array_except_self.cpp](./238_product_of_array_except_self.cpp)。
- 掌握状态：前后缀积模板。

## 背诵答案

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;
}
```

## 背诵口诀

> 从左到右存前缀，从右到左乘后缀。
> 先更新答案，再更新后缀。

第一遍遍历后，`ans[i]` 是 `nums[i]` 左边所有元素的乘积：

```cpp
ans[i] = ans[i - 1] * nums[i - 1];
```

第二遍从右向左遍历，`suffix` 是 `nums[i]` 右边所有元素的乘积。先将它乘入答案，再把当前元素加入后缀：

```cpp
ans[i] *= suffix;
suffix *= nums[i];
```

这样不会把 `nums[i]` 自身乘进 `ans[i]`。

## 易错点

- 题目要求不能使用除法。
- 前缀积和后缀积的初始值都是乘法单位元 `1`。
- 更新顺序不能反：必须先 `ans[i] *= suffix`，再 `suffix *= nums[i]`。
- 零不需要特殊处理，这种写法会自然得到正确结果。
- 题目保证任意前缀积和后缀积都在 32 位整数范围内。

时间复杂度为 `O(n)`。除返回数组外，只使用一个 `suffix` 变量，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/prefix_sum/238_product_of_array_except_self.cpp -o build/238
./build/238
```
