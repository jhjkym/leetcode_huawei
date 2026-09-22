# 35. 搜索插入位置

- 算法分类：二分查找、左边界。
- 数据结构：升序数组。
- 对应代码：[035_search_insert_position.cpp](./035_search_insert_position.cpp)。
- 掌握状态：左闭右开二分模板。

## 背诵答案

```cpp
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

## 背诵口诀

> 找第一个大于等于目标的位置；
> 小于目标，左边去 `mid + 1`；
> 否则右边收缩到 `mid`。

搜索区间是左闭右开区间：

```text
[left, right)
```

因此：

- `right` 初始化为 `nums.size()`，允许答案位于数组末尾；
- 循环条件是 `left < right`；
- `nums[mid] >= target` 时，`mid` 仍可能是答案，所以执行 `right = mid`；
- 循环结束时 `left == right`，就是第一个大于等于目标的位置。

这个位置既是目标存在时的下标，也是目标不存在时保持数组有序的插入位置。

## 易错点

- 左闭右开模板中，右边界更新为 `right = mid`，不是 `mid - 1`。
- 左边界更新为 `left = mid + 1`，否则可能死循环。
- 返回 `left`，不需要额外判断目标是否存在。
- 使用 `left + (right - left) / 2` 计算中点。

时间复杂度为 `O(log n)`，额外空间复杂度为 `O(1)`。

## 编译运行

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/binary_search/035_search_insert_position.cpp -o build/035
./build/035
```
