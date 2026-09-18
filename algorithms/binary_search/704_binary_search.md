# 704. 二分查找

- 算法分类：二分查找。
- 数据结构：升序数组。
- 对应代码：[704_binary_search.cpp](./704_binary_search.cpp)。
- 掌握状态：基础模板。

## 背诵答案

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

这里使用闭区间 `[left, right]`。每次比较中间值：中间值小于目标就排除左半部分，中间值大于目标就排除右半部分。循环条件使用 `left <= right`，因为只剩一个元素时仍然需要检查。

`mid` 使用 `left + (right - left) / 2`，避免直接写 `(left + right) / 2` 可能产生的整数溢出。

时间复杂度 `O(log n)`，空间复杂度 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/704_binary_search.cpp -o build/704
./build/704
```
