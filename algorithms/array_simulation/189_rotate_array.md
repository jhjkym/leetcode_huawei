# 189. 轮转数组

- 算法分类：数组模拟、三次翻转。
- 数据结构：数组 `vector<int>`。
- 对应代码：[189_rotate_array.cpp](./189_rotate_array.cpp)。
- 掌握状态：三次翻转模板。

## 背诵答案

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
```

## 背诵口诀

> 先全部翻转，再翻前 `k` 个，最后翻剩下的。

例如将 `[1,2,3,4,5,6,7]` 向右轮转 `3` 位：

```text
整体翻转： [7,6,5,4,3,2,1]
翻前 3 个：[5,6,7,4,3,2,1]
翻剩余：   [5,6,7,1,2,3,4]
```

## 易错点

- 先执行 `k %= n`，因为 `k` 可能大于数组长度。
- 第二次翻转的区间是 `[begin, begin + k)`，不包含 `begin + k`。
- 第三次翻转从 `begin + k` 开始。
- 官方约束保证数组非空，因此 `k %= n` 不会除以零。

时间复杂度为 `O(n)`，空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/array_simulation/189_rotate_array.cpp -o build/189
./build/189
```
